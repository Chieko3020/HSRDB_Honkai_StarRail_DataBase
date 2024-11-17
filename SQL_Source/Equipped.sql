USE [HSRDB]
GO
CREATE TABLE [dbo].[Equipped](
	[Concept] [nvarchar](50) NOT NULL,
	[Eidolons] [int] NULL,
	[LightCone] [nvarchar](50) NULL,
	[SuperimposeLevel] [int] NULL,
	[Head] [smallint] NULL,
	[Hands] [smallint] NULL,
	[Body] [smallint] NULL,
	[Feet] [smallint] NULL,
	[PlanarSphere] [smallint] NULL,
	[LinkRope] [smallint] NULL,
	[HP] decimal(6,2) NOT NULL,
	[ATK] decimal(6,2) NOT NULL,
	[DEF] decimal(6,2) NOT NULL,
	[SPD] decimal(6,2) NOT NULL,
	[CritRate] decimal(8, 4) NULL,
	[CritDMG] decimal(8, 4) NULL,
	[BreakEffect] decimal(8, 4) NULL,
	[OutgoingHealingBoost] decimal(8, 4) NULL,
	[EnergyRegenerationRate] decimal(8, 4) NULL,
	[EffectHitRate] decimal(8, 4) NULL,
	[EffectRES] decimal(8, 4) NULL,
	[HPBoost] [smallint] NULL,
	[ATKBoost] [smallint] NULL,
	[DEFBoost] [smallint] NULL,
	[SPDBoost] [smallint] NULL,
	[HPBoostPercentage] decimal(8, 4) NULL,
	[ATKBoostPercentage] decimal(8, 4) NULL,
	[DEFBoostPercentage] decimal(8, 4) NULL,
	[SPDBoostPercentage] decimal(8, 4) NULL,
	[PhysicalDMGBoost] decimal(8, 4) NULL,
	[FireDMGBoost] decimal(8, 4) NULL,
	[IceDMGBoost] decimal(8, 4) NULL,
	[LightningDMGBoost] decimal(8, 4) NULL,
	[WindDMGBoost] decimal(8, 4) NULL,
	[QuantumDMGBoost] decimal(8, 4) NULL,
	[ImaginaryDMGBoost] decimal(8, 4) NULL,
	[SetCritRate] decimal(8, 4) NULL,
	[SetCritDMG] decimal(8, 4) NULL,
	[SetBreakEffect] decimal(8, 4) NULL,
	[SetOutgoingHealingBoost] decimal(8, 4) NULL,
	[SetEnergyRegenerationRate] decimal(8, 4) NULL,
	[SetEffectHitRate] decimal(8, 4) NULL,
	[SetEffectRES] decimal(8, 4) NULL,
	[SetHPBoostPercentage] decimal(8, 4) NULL,
	[SetATKBoostPercentage] decimal(8, 4) NULL,
	[SetDEFBoostPercentage] decimal(8, 4) NULL,
	[SetSPDBoostPercentage] decimal(8, 4) NULL,
	[SetPhysicalDMGBoost] decimal(8, 4) NULL,
	[SetFireDMGBoost] decimal(8, 4) NULL,
	[SetIceDMGBoost] decimal(8, 4) NULL,
	[SetLightningDMGBoost] decimal(8, 4) NULL,
	[SetWindDMGBoost] decimal(8, 4) NULL,
	[SetQuantumDMGBoost] decimal(8, 4) NULL,
	[SetImaginaryDMGBoost] decimal(8, 4) NULL,
PRIMARY KEY CLUSTERED 
(
	[Concept] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_Eidolons] DEFAULT ((0)) FOR [Eidolons]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SuperimposeLevel] DEFAULT ((0)) FOR [SuperimposeLevel]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_HP] DEFAULT ((0)) FOR [HP]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_ATK] DEFAULT ((0)) FOR [ATK]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_DEF] DEFAULT ((0)) FOR [DEF]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SPD] DEFAULT ((0)) FOR [SPD]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_CritRate] DEFAULT ((0.05)) FOR [CritRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_CritDMG] DEFAULT ((0.5)) FOR [CritDMG]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_BreakEffect] DEFAULT ((0)) FOR [BreakEffect]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_OutgoingHealingBoost] DEFAULT ((0)) FOR [OutgoingHealingBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_EnergyRegenerationRate] DEFAULT ((1)) FOR [EnergyRegenerationRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_EffectHitRate] DEFAULT ((0)) FOR [EffectHitRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_EffectRES] DEFAULT ((0)) FOR [EffectRES]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_HPBoost] DEFAULT ((0)) FOR [HPBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_ATKBoost] DEFAULT ((0)) FOR [ATKBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_DEFBoost] DEFAULT ((0)) FOR [DEFBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SPDBoost] DEFAULT ((0)) FOR [SPDBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_HPBoostPercentage] DEFAULT ((0)) FOR [HPBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_ATKBoostPercentage] DEFAULT ((0)) FOR [ATKBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_DEFBoostPercentage] DEFAULT ((0)) FOR [DEFBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SPDBoostPercentage] DEFAULT ((0)) FOR [SPDBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_PhysicalDMGBoost] DEFAULT ((0)) FOR [PhysicalDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_FireDMGBoost] DEFAULT ((0)) FOR [FireDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_IceDMGBoost] DEFAULT ((0)) FOR [IceDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_LightningDMGBoost] DEFAULT ((0)) FOR [LightningDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_WindDMGBoost] DEFAULT ((0)) FOR [WindDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_QuantumDMGBoost] DEFAULT ((0)) FOR [QuantumDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_ImaginaryDMGBoost] DEFAULT ((0)) FOR [ImaginaryDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetCritRate] DEFAULT ((0)) FOR [SetCritRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetCritDMG] DEFAULT ((0)) FOR [SetCritDMG]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetBreakEffect] DEFAULT ((0)) FOR [SetBreakEffect]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetOutgoingHealingBoost] DEFAULT ((0)) FOR [SetOutgoingHealingBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetEnergyRegenerationRate] DEFAULT ((0)) FOR [SetEnergyRegenerationRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetEffectHitRate] DEFAULT ((0)) FOR [SetEffectHitRate]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetEffectRES] DEFAULT ((0)) FOR [SetEffectRES]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetHPBoostPercentage] DEFAULT ((0)) FOR [SetHPBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetATKBoostPercentage] DEFAULT ((0)) FOR [SetATKBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetDEFBoostPercentage] DEFAULT ((0)) FOR [SetDEFBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetSPDBoostPercentage] DEFAULT ((0)) FOR [SetSPDBoostPercentage]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetPhysicalDMGBoost] DEFAULT ((0)) FOR [SetPhysicalDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetFireDMGBoost] DEFAULT ((0)) FOR [SetFireDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetIceDMGBoost] DEFAULT ((0)) FOR [SetIceDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetLightningDMGBoost] DEFAULT ((0)) FOR [SetLightningDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetWindDMGBoost] DEFAULT ((0)) FOR [SetWindDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetQuantumDMGBoost] DEFAULT ((0)) FOR [SetQuantumDMGBoost]
GO
ALTER TABLE [dbo].[Equipped] ADD CONSTRAINT [DF_Equipped_SetImaginaryDMGBoost] DEFAULT ((0)) FOR [SetImaginaryDMGBoost]
GO
ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Character] FOREIGN KEY([Concept]) REFERENCES [dbo].[Characters] ([Concept])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Character]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_LightCone] FOREIGN KEY([LightCone]) REFERENCES [dbo].[LightCones] ([Concept])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_LightCone]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_Head] FOREIGN KEY([Head]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_Head]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_Hands] FOREIGN KEY([Hands]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_Hands]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_Body] FOREIGN KEY([Body]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_Body]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_Feet] FOREIGN KEY([Feet]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_Feet]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_PlanarSphere] FOREIGN KEY([PlanarSphere]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_PlanarSphere]
GO

ALTER TABLE [dbo].[Equipped]  WITH CHECK ADD CONSTRAINT [FK_Equipped_Relics_LinkRope] FOREIGN KEY([LinkRope]) REFERENCES [dbo].[Relics] ([ID])
GO
ALTER TABLE [dbo].[Equipped] CHECK CONSTRAINT [FK_Equipped_Relics_LinkRope]
GO



