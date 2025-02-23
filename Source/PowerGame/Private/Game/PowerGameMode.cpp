// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PowerGameMode.h"

#include "Engine/PointLight.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"

void APowerGameMode::BeginPlay()
{
	Super::BeginPlay();
	SwitchLights(false);
}

void APowerGameMode::SwitchLights(bool bIsOn)
{
	//Get each point light in the level and switch them on or off based on Bool bIsOn
	TArray<AActor*> PointLights;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APointLight::StaticClass(), PointLights);
	for (AActor* PointLight : PointLights)
	{
		APointLight* Light = Cast<APointLight>(PointLight);
		if (Light)
		{
			Light->SetActorHiddenInGame(!bIsOn);
		}
	}

	
    // Get each static mesh in the level and enable or disable emissiveness based on Bool bIsOn
    TArray<AActor*> StaticMeshes;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), StaticMeshes);
    for (AActor* StaticMeshActor : StaticMeshes)
    {
	    AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(StaticMeshActor);
    	if (MeshActor && MeshActor->GetStaticMeshComponent())
    	{
    		UStaticMeshComponent* MeshComponent = MeshActor->GetStaticMeshComponent();
    		int32 MaterialCount = MeshComponent->GetNumMaterials();
    		for (int32 i = 0; i < MaterialCount; ++i)
    		{
    			//UE_LOG the material name
    			UE_LOG(LogTemp, Warning, TEXT("Material: %s"), *MeshComponent->GetMaterial(i)->GetName());
    			
    			// Create a dynamic material instance
    			UMaterialInstanceDynamic* DynamicMaterial = MeshComponent->CreateAndSetMaterialInstanceDynamic(i);
    			if (DynamicMaterial)
    			{
    				// Log the material name
    				UE_LOG(LogTemp, Warning, TEXT("Material: %s"), *DynamicMaterial->GetName());

    				// Check if the material has a parameter called "LightsOn"
    				float EmissiveValue;
    				if (DynamicMaterial->GetScalarParameterValue(FName("LightsOn"), EmissiveValue))
    				{
    					// Log the current emissive value
    					UE_LOG(LogTemp, Warning, TEXT("Current LightsOn Value: %f"), EmissiveValue);

    					// Set the value for "LightsOn" to bIsOn
    					DynamicMaterial->SetScalarParameterValue(FName("LightsOn"), bIsOn ? 1.0f : 0.0f);

    					// Log the new emissive value
    					DynamicMaterial->GetScalarParameterValue(FName("LightsOn"), EmissiveValue);
    					UE_LOG(LogTemp, Warning, TEXT("New LightsOn Value: %f"), EmissiveValue);
    				}
    				else
    				{
    					UE_LOG(LogTemp, Error, TEXT("Material does not have an LightsOn parameter"));
    				}
    			}
    		}
    	}
    }
	
}
