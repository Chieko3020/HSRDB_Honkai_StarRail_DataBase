USE [HSRDB]
GO

CREATE TRIGGER [dbo].[AddCharacter] ON [dbo].[Equipped]
AFTER INSERT
AS
BEGIN
IF UPDATE(Concept)
BEGIN
	SET NOCOUNT ON;
	DECLARE @Character nvarchar(50);
	DECLARE @Eidolons int;
	DECLARE @TraceBoostPercentage1 nvarchar(20);
	DECLARE @TraceBoostPercentageValue1 decimal(8, 4);
	DECLARE @TraceBoostPercentage2 nvarchar(20);
	DECLARE @TraceBoostPercentageValue2 decimal(8, 4);
	DECLARE @TraceBoostPercentage3 nvarchar(20);
	DECLARE @TraceBoostPercentageValue3 decimal(8, 4);
	DECLARE @TraceBoostSPDValue smallint;
	SELECT @Character=inserted.Concept FROM inserted
	SELECT @Eidolons=Characters.Eidolons FROM Characters WHERE Characters.Concept=@Character
	SELECT @TraceBoostPercentage1=Characters.TraceBoostPercentage1 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostPercentageValue1=Characters.TraceBoostPercentageValue1 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostPercentage2=Characters.TraceBoostPercentage2 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostPercentageValue2=Characters.TraceBoostPercentageValue2 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostPercentage3=Characters.TraceBoostPercentage3 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostPercentageValue3=Characters.TraceBoostPercentageValue3 FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	SELECT @TraceBoostSPDValue=Characters.TraceBoostSPDValue FROM Characters,inserted WHERE inserted.Concept=Characters.Concept
	UPDATE Equipped
	SET Eidolons=@Eidolons WHERE Equipped.Concept=@Character;
	UPDATE Equipped
	SET HP=HP+(SELECT Characters.HP FROM Characters,inserted WHERE inserted.Concept=Characters.Concept) WHERE Equipped.Concept=@Character
	UPDATE Equipped
	SET ATK=ATK+(SELECT Characters.ATK FROM Characters,inserted WHERE inserted.Concept=Characters.Concept) WHERE Equipped.Concept=@Character
	UPDATE Equipped
	SET DEF=DEF+(SELECT Characters.DEF FROM Characters,inserted WHERE inserted.Concept=Characters.Concept) WHERE Equipped.Concept=@Character
	UPDATE Equipped
	SET SPD=SPD+(SELECT Characters.SPD FROM Characters,inserted WHERE inserted.Concept=Characters.Concept) WHERE Equipped.Concept=@Character
	IF(@TraceBoostPercentage1='CritRate')
	BEGIN
		UPDATE Equipped
		SET CritRate=CritRate+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='CritDMG')
	BEGIN
		UPDATE Equipped
		SET CritDMG=CritDMG+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='BreakEffect')
	BEGIN
		UPDATE Equipped
		SET BreakEffect=BreakEffect+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='EffectHitRate')
	BEGIN
		UPDATE Equipped
		SET EffectHitRate=EffectHitRate+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='EffectRES')
	BEGIN
		UPDATE Equipped
		SET EffectRES=EffectRES+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='HPBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET HPBoostPercentage=HPBoostPercentage+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='ATKBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET ATKBoostPercentage=ATKBoostPercentage+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='DEFBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET DEFBoostPercentage=DEFBoostPercentage+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='PhysicalDMGBoost')
	BEGIN
		UPDATE Equipped
		SET PhysicalDMGBoost=PhysicalDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='FireDMGBoost')
	BEGIN
		UPDATE Equipped
		SET FireDMGBoost=FireDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='IceDMGBoost')
	BEGIN
		UPDATE Equipped
		SET IceDMGBoost=IceDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='LightningDMGBoost')
	BEGIN
		UPDATE Equipped
		SET LightningDMGBoost=LightningDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='WindDMGBoost')
	BEGIN
		UPDATE Equipped
		SET WindDMGBoost=WindDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='QuantumDMGBoost')
	BEGIN
		UPDATE Equipped
		SET QuantumDMGBoost=QuantumDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage1='ImaginaryDMGBoost')
	BEGIN
		UPDATE Equipped
		SET ImaginaryDMGBoost=ImaginaryDMGBoost+@TraceBoostPercentageValue1 WHERE Equipped.Concept=@Character;
	END
	IF(@TraceBoostPercentage2='CritRate')
	BEGIN
		UPDATE Equipped
		SET CritRate=CritRate+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='CritDMG')
	BEGIN
		UPDATE Equipped
		SET CritDMG=CritDMG+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='BreakEffect')
	BEGIN
		UPDATE Equipped
		SET BreakEffect=BreakEffect+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='EffectHitRate')
	BEGIN
		UPDATE Equipped
		SET EffectHitRate=EffectHitRate+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='EffectRES')
	BEGIN
		UPDATE Equipped
		SET EffectRES=EffectRES+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='HPBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET HPBoostPercentage=HPBoostPercentage+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='ATKBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET ATKBoostPercentage=ATKBoostPercentage+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='DEFBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET DEFBoostPercentage=DEFBoostPercentage+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='PhysicalDMGBoost')
	BEGIN
		UPDATE Equipped
		SET PhysicalDMGBoost=PhysicalDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='FireDMGBoost')
	BEGIN
		UPDATE Equipped
		SET FireDMGBoost=FireDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='FireDMGBoost')
	BEGIN
		UPDATE Equipped
		SET FireDMGBoost=FireDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='IceDMGBoost')
	BEGIN
		UPDATE Equipped
		SET IceDMGBoost=IceDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='LightningDMGBoost')
	BEGIN
		UPDATE Equipped
		SET LightningDMGBoost=LightningDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='WindDMGBoost')
	BEGIN
		UPDATE Equipped
		SET WindDMGBoost=WindDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='QuantumDMGBoost')
	BEGIN
		UPDATE Equipped
		SET QuantumDMGBoost=QuantumDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage2='ImaginaryDMGBoost')
	BEGIN
		UPDATE Equipped
		SET ImaginaryDMGBoost=ImaginaryDMGBoost+@TraceBoostPercentageValue2 WHERE Equipped.Concept=@Character;
	END
	IF(@TraceBoostPercentage3='CritRate')
	BEGIN
		UPDATE Equipped
		SET CritRate=CritRate+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='CritDMG')
	BEGIN
		UPDATE Equipped
		SET CritDMG=CritDMG+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='BreakEffect')
	BEGIN
		UPDATE Equipped
		SET BreakEffect=BreakEffect+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='EffectHitRate')
	BEGIN
		UPDATE Equipped
		SET EffectHitRate=EffectHitRate+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='EffectRES')
	BEGIN
		UPDATE Equipped
		SET EffectRES=EffectRES+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='HPBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET HPBoostPercentage=HPBoostPercentage+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='ATKBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET ATKBoostPercentage=ATKBoostPercentage+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='DEFBoostPercentage')
	BEGIN
		UPDATE Equipped
		SET DEFBoostPercentage=DEFBoostPercentage+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='PhysicalDMGBoost')
	BEGIN
		UPDATE Equipped
		SET PhysicalDMGBoost=PhysicalDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='FireDMGBoost')
	BEGIN
		UPDATE Equipped
		SET FireDMGBoost=FireDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='FireDMGBoost')
	BEGIN
		UPDATE Equipped
		SET FireDMGBoost=FireDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='IceDMGBoost')
	BEGIN
		UPDATE Equipped
		SET IceDMGBoost=IceDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='LightningDMGBoost')
	BEGIN
		UPDATE Equipped
		SET LightningDMGBoost=LightningDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='WindDMGBoost')
	BEGIN
		UPDATE Equipped
		SET WindDMGBoost=WindDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='QuantumDMGBoost')
	BEGIN
		UPDATE Equipped
		SET QuantumDMGBoost=QuantumDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostPercentage3='ImaginaryDMGBoost')
	BEGIN
		UPDATE Equipped
		SET ImaginaryDMGBoost=ImaginaryDMGBoost+@TraceBoostPercentageValue3 WHERE Equipped.Concept=@Character;
	END
	ELSE IF(@TraceBoostSPDValue IS NOT NULL)
	BEGIN
		UPDATE Equipped
		SET SPD=SPD+@TraceBoostSPDValue WHERE Equipped.Concept=@Character;
	END
END
END
GO
ALTER TABLE [dbo].[Equipped] ENABLE TRIGGER [AddCharacter]
GO

