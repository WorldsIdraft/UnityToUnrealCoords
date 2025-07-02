// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnityCoordConverterBPLibrary.h"
#include "UnityCoordConverter.h"

UUnityCoordConverterBPLibrary::UUnityCoordConverterBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UUnityCoordConverterBPLibrary::UnityCoordConverterSampleFunction(float Param)
{
	return -1;
}

FVector UUnityCoordConverterBPLibrary::UnityPos(FVector UnityPosition)
{
	FVector UEPosition = FVector(UnityPosition.Z, UnityPosition.X, UnityPosition.Y);
	UEPosition *= 100.0f;
	return UEPosition;
}

FRotator UUnityCoordConverterBPLibrary::UnityRot(FVector UnityEuler)
{
    // Normalize to range [-180, 180]
    auto NormalizeAngle = [](float Angle) -> float {
        float Result = FMath::Fmod(Angle, 360.0f);
        if (Result > 180.0f) Result -= 360.0f;
        if (Result < -180.0f) Result += 360.0f;
        return Result;
        };

    float UnityPitch = UnityEuler.X;
    float UnityYaw = UnityEuler.Y;
    float UnityRoll = UnityEuler.Z;

    float Pitch = -NormalizeAngle(UnityPitch);
    float Yaw = NormalizeAngle(UnityYaw);
    float Roll = -NormalizeAngle(UnityRoll);

    return FRotator(Pitch, Yaw, Roll);
}

FVector UUnityCoordConverterBPLibrary::UnityScale(FVector UnityScale)
{
	FVector UEScale = FVector(UnityScale.Z, UnityScale.X, UnityScale.Y);
	UEScale = UEScale / 100.0f;
	return UEScale;
}