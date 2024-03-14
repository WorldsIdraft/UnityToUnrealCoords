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

FRotator UUnityCoordConverterBPLibrary::UnityRot(FRotator unityRotation)
{
    /* In Unity, rotations are represented as Euler angles in degrees.
     Unreal Engine uses a different order for Euler angles (Pitch, Yaw, Roll) and radians.
    Convert the Unity rotation to Unreal rotation.
    Roll = X
    Pitch = Y
    Yaw = Z
    */

    // Swap the pitch and yaw angles
    float UE_X = unityRotation.Roll;
    float UE_Y = unityRotation.Yaw;
    float UE_Z = -unityRotation.Pitch;

    // Create the Unreal Engine FRotator
    FRotator ueRotation = FRotator(UE_X, UE_Y, UE_Z);

    return ueRotation;
}

FVector UUnityCoordConverterBPLibrary::UnityScale(FVector UnityScale)
{
	FVector UEScale = FVector(UnityScale.Z, UnityScale.X, UnityScale.Y);
	UEScale = UEScale / 100.0f;
	return UEScale;
}