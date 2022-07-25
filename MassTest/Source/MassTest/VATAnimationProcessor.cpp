// Fill out your copyright notice in the Description page of Project Settings.


#include "VATAnimationProcessor.h"
#include "MassRepresentationFragments.h"
#include "MassCommonFragments.h"
#include "MassMovementFragments.h"
#include "AgentFragment.h"


UVATAnimationProcessor::UVATAnimationProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
}

void UVATAnimationProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FMassVelocityFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FMassRepresentationLODFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FAgentFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FMassRepresentationFragment>(EMassFragmentAccess::ReadWrite);
	//EntityQuery.AddChunkRequirement<FMassVisualizationChunkFragment>(EMassFragmentAccess::ReadOnly);
	//EntityQuery.SetChunkFilter(&FMassVisualizationChunkFragment::AreAnyEntitiesVisibleInChunk);
}

void UVATAnimationProcessor::Initialize(UObject& Owner)
{
	RepresentationSubsystem = UWorld::GetSubsystem<UMassRepresentationSubsystem>(Owner.GetWorld());
}

void UVATAnimationProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	FMassInstancedStaticMeshInfoArrayView ISMInfoList = RepresentationSubsystem->GetMutableInstancedStaticMeshInfos();

	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this, &ISMInfoList](FMassExecutionContext& Context)
		{
			const TConstArrayView<FMassVelocityFragment> VelocityList = Context.GetFragmentView<FMassVelocityFragment>();
			const TConstArrayView<FTransformFragment> TransformList = Context.GetFragmentView<FTransformFragment>();
			const TConstArrayView<FMassRepresentationLODFragment> RepresentationLODList = Context.GetFragmentView<FMassRepresentationLODFragment>();
			const TArrayView<FMassRepresentationFragment> RepresentationList = Context.GetMutableFragmentView<FMassRepresentationFragment>();
			const TArrayView<FAgentFragment> AgentList = Context.GetMutableFragmentView<FAgentFragment>();

			TArray<float> CustomData({0.f, 0.f, 0.f});
			//CustomData.Reserve(3);

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); EntityIndex++)
			{
				const FMassVelocityFragment& Velocity = VelocityList[EntityIndex];
				const FTransformFragment& Transform = TransformList[EntityIndex];
				const FMassRepresentationLODFragment& RepresentationLOD = RepresentationLODList[EntityIndex];
				FAgentFragment& AgentData = AgentList[EntityIndex];
				FMassRepresentationFragment& Representation = RepresentationList[EntityIndex];

				if (Representation.CurrentRepresentation == EMassRepresentationType::StaticMeshInstance)
				{
					auto AnimationValue = 0.f;
					const auto Speed = Velocity.Value.Length();

					// Could be Tuneable values otherwise move to const
					if (Speed > 30.f && Speed <= 400.f)
					{
						AnimationValue = 0.5f;
					}
					else if(Speed > 400.f)
					{
						AnimationValue = 1.f;
					}

					// TODO: could be set in an Observer Processor?
					if (AgentData.SkinIndex == -1)
					{
						AgentData.SkinIndex = FMath::RandRange(0.f, 3.f);
					}

					CustomData[0] = AgentData.SkinIndex;
					CustomData[1] = AnimationValue;

					ISMInfoList[Representation.StaticMeshDescIndex].AddBatchedCustomDataFloats(CustomData, RepresentationLOD.LODSignificance, Representation.PrevLODSignificance);
					Representation.PrevTransform = Transform.GetTransform();
					Representation.PrevLODSignificance = RepresentationLOD.LODSignificance;
				}
			}
		}));
}
