// Fill out your copyright notice in the Description page of Project Settings.


#include "SupportalCombatCharacterAI.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "SupportalCombat.h"

// Sets default values
ASupportalCombatCharacterAI::ASupportalCombatCharacterAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add the Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(AscReplicationMode);

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Add the basic attribute set
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>(TEXT("BasicAttributeSet"));
}

// Called when the game starts or when spawned
void ASupportalCombatCharacterAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASupportalCombatCharacterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASupportalCombatCharacterAI::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void ASupportalCombatCharacterAI::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ASupportalCombatCharacterAI::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void ASupportalCombatCharacterAI::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void ASupportalCombatCharacterAI::PossessedBy(AController* NewController) 
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent) 
	{
		AbilitySystemComponent->InitAbilityActorInfo(/*InOwnerActor=*/ this, /*InAvatarActor=*/ this);
	}
}

UAbilitySystemComponent* ASupportalCombatCharacterAI::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
