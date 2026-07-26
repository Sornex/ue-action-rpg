#include "Items/Item.h"
#include "ActionRPG/DebugMacros.h"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemStaticMesh"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Runtime += DeltaTime;
	
	float RotationSpeed = 15.0f;
	
	FString Message = FString::Printf(TEXT("Delta Time: %f"), DeltaTime);
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Red, Message);
	}
	
	AddActorWorldRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
}

