#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Tess.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

UCLASS()
class ACTIONRPG_API ATess : public ACharacter
{
	GENERATED_BODY()

public:
	ATess();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext> PlayerMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> ViewCamera;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGroomComponent> Hair;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGroomComponent> EyeBrows;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

};
