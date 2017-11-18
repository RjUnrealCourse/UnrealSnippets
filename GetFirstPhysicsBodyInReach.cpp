// check and add required headers
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"




#define OUT


/**
 * Send a ray cast and send the first physics body hit
 * @return  HitResult   Raycast result
 */
FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{    
    FHitResult HitResult;
    FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
    
    // reach line start and end to find objects on
    FVector Start = GetReachLineStart();
    FVector End = GetReachLineEnd();

    /// Line-trace (AKA ray-cast) out to reach distance
    /// ===============================================
    bool bFoundHit =
        GetWorld()->LineTraceSingleByObjectType(
            OUT HitResult,
            Start,
            End,
            FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
            TraceParameters
        );
    /// ===============================================


    return HitResult;
}
