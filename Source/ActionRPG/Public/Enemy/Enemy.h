
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UAnimMontage;
class UAttributeComponent;
class UHealthBarComponent;

UCLASS()
class ACTIONRPG_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	void DirectionalHitReact(const FVector& ImpactPoint) const;
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
protected:
	virtual void BeginPlay() override;
	
	void Die();
	
	/**
	 * Play Montage functions
	 */
	
	void PlayHitReactMontage(const FName& SectionName) const;
	
	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;
private:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAttributeComponent> Attributes;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHealthBarComponent> HealthBarWidget;
	/**
	 * Animation montages
	 */
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	TObjectPtr<UAnimMontage> HitReactMontage;
	
	UPROPERTY(EditAnywhere, Category = Sounds)
	TObjectPtr<USoundBase> HitReactSound;

	UPROPERTY(EditAnywhere, Category = VisualEffects)
	UParticleSystem* HitReactParticles;
	
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* DeathMontage;
	
	UPROPERTY()
	AActor* CombatTarget;

	UPROPERTY(EditAnywhere)
	double CombatRadius = 500.f;
public:
};
