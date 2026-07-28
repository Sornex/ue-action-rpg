// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TessAnimInstance.h"
#include "Characters/Tess.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UTessAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	Tess = Cast<ATess>(TryGetPawnOwner());
	
	if (Tess)
	{
		TessMovement = Tess->GetCharacterMovement();
	}
}

void UTessAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (TessMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(TessMovement->Velocity);
		IsFalling = TessMovement->IsFalling();
		CharacterState = Tess->GetCharacterState();
	}
}
