USE [HSRDB]
GO
CREATE VIEW [dbo].[Panel](Concept,Eidolons,LightCone,SuperimposeLevel,
			HP,ATK,DEF,SPD,
			CritRate,CritDMG,
			BreakEffect,
			OutgoingHealingBoost,EnergyRegenerationRate,
			EffectHitRate,EffectRES,
			PhysicalDMGBoost,
			FireDMGBoost,
			IceDMGBoost,
			LightningDMGBoost,
			WindDMGBoost,
			QuantumDMGBoost,
			ImaginaryDMGBoost)
AS SELECT   Concept,Eidolons,LightCone,SuperimposeLevel,
			HP+HPBoost+HP*(HPBoostPercentage+SetHPBoostPercentage),
			ATK+ATKBoost+ATK*(ATKBoostPercentage+SetATKBoostPercentage),
			DEF+DEFBoost+DEF*(DEFBoostPercentage+SetDEFBoostPercentage),
			SPD+SPDBoost+SPD*(SPDBoostPercentage+SetSPDBoostPercentage),
			CritRate+SetCritRate,CritDMG+SetCritDMG,
			BreakEffect+SetBreakEffect,
			OutgoingHealingBoost+SetOutgoingHealingBoost,EnergyRegenerationRate+SetEnergyRegenerationRate,
			EffectHitRate+SetEffectHitRate,EffectRES+SetEffectRES,
			PhysicalDMGBoost+SetPhysicalDMGBoost,
			FireDMGBoost+SetFireDMGBoost,
			IceDMGBoost+SetIceDMGBoost,
			LightningDMGBoost+SetLightningDMGBoost,
			WindDMGBoost+SetWindDMGBoost,
			QuantumDMGBoost+SetQuantumDMGBoost,
			ImaginaryDMGBoost+SetImaginaryDMGBoost 
FROM Equipped;
GO
