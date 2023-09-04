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
    // In Unity, rotations are represented as Euler angles in degrees.
    // Unreal Engine uses a different order for Euler angles (Pitch, Yaw, Roll) and radians.
    // Convert the Unity rotation to Unreal rotation.

    // Swap the pitch and yaw angles
    float pitch = unityRotation.Roll;
    float yaw = unityRotation.Pitch;
    float roll = unityRotation.Yaw;

    // Invert the yaw angle
    pitch = -pitch;

    // Create the Unreal Engine FRotator
    FRotator ueRotation = FRotator(pitch, yaw, roll);

    return ueRotation;
}