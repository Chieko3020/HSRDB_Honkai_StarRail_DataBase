USE [HSRDB]
GO

CREATE TRIGGER [dbo].[RemoveLC] ON [dbo].[Equipped]
AFTER UPDATE
AS
BEGIN
IF UPDATE(LightCone)
BEGIN
	SET NOCOUNT ON;
	DECLARE @LightCone nvarchar(50);
	DECLARE @Character nvarchar(50);
	DECLARE @LCBoostPercentage1 nvarchar(20);
	DECLARE @LCBoostPercentageValue1 decimal(8, 4);
	DECLARE @LCBoostPercentage2 nvarchar(20);
	DECLARE @LCBoostPercentageValue2 decimal(8, 4);
	SELECT @Character=inserted.Concept FROM inserted;
	SELECT @LightCone=deleted.LightCone FROM deleted WHERE deleted.LightCone IS NOT NULL AND EXISTS(SELECT * FROM inserted WHERE inserted.Concept=deleted.Concept AND inserted.LightCone IS NULL);
	IF (@LightCone IS NOT NULL)
	BEGIN
	SELECT @LCBoostPercentage1=LightCones.LCBoostPercentage1 FROM LightCones WHERE LightCones.Concept=@LightCone;
	SELECT @LCBoostPercentageValue1=LightCones.LCBoostPercentageValue1 FROM LightCones WHERE LightCones.Concept=@LightCone;
	SELECT @LCBoostPercentage2=LightCones.LCBoostPercentage2 FROM LightCones WHERE LightCones.Concept=@LightCone;
	SELECT @LCBoostPercentageValue2=LightCones.LCBoostPercentageValue2 FROM LightCones WHERE LightCones.Concept=@LightCone;
	END
	IF (@LightCone IS NOT NULL)
	BEGIN
	    UPDATE Equipped
		SET Equipped.SuperimposeLevel=0 WHERE Equipped.Concept=@Character;
		UPDATE Equipped
		SET Equipped.HP=Equipped.HP-(SELECT HP FROM LightCones WHERE LightCones.Concept=@LightCone) WHERE Equipped.Concept=@Character;
		UPDATE Equipped
		SET Equipped.ATK=Equipped.ATK-(SELECT ATK FROM LightCones WHERE LightCones.Concept=@LightCone) WHERE Equipped.Concept=@Character;
		UPDATE Equipped
		SET Equipped.DEF=Equipped.DEF-(SELECT DEF FROM LightCones WHERE LightCones.Concept=@LightCone) WHERE Equipped.Concept=@Character;
		IF(@LCBoostPercentage1 IS NOT NULL)
		BEGIN
			IF(@LCBoostPercentage1='CritRate')
			BEGIN
				UPDATE Equipped
				SET CritRate=CritRate-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='CritDMG')
			BEGIN
				UPDATE Equipped
				SET CritDMG=CritDMG-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='BreakEffect')
			BEGIN
				UPDATE Equipped
				SET BreakEffect=BreakEffect-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='EffectHitRate')
			BEGIN
				UPDATE Equipped
				SET EffectHitRate=EffectHitRate-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='EffectRES')
			BEGIN
				UPDATE Equipped
				SET EffectRES=EffectRES-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='HPBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET HPBoostPercentage=HPBoostPercentage-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='ATKBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET ATKBoostPercentage=ATKBoostPercentage-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage1='DEFBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET DEFBoostPercentage=DEFBoostPercentage-@LCBoostPercentageValue1 WHERE Equipped.Concept=@Character;
			END			
		END
		IF(@LCBoostPercentage2 IS NOT NULL)
		BEGIN
			IF(@LCBoostPercentage2='CritRate')
			BEGIN
				UPDATE Equipped
				SET CritRate=CritRate-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='CritDMG')
			BEGIN
				UPDATE Equipped
				SET CritDMG=CritDMG-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='BreakEffect')
			BEGIN
				UPDATE Equipped
				SET BreakEffect=BreakEffect-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='EffectHitRate')
			BEGIN
				UPDATE Equipped
				SET EffectHitRate=EffectHitRate-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='EffectRES')
			BEGIN
				UPDATE Equipped
				SET EffectRES=EffectRES-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='HPBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET HPBoostPercentage=HPBoostPercentage-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='ATKBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET ATKBoostPercentage=ATKBoostPercentage-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END
			ELSE IF(@LCBoostPercentage2='DEFBoostPercentage')
			BEGIN
				UPDATE Equipped
				SET DEFBoostPercentage=DEFBoostPercentage-@LCBoostPercentageValue2 WHERE Equipped.Concept=@Character;
			END			
		END
	END
END
END
GO

ALTER TABLE [dbo].[Equipped] ENABLE TRIGGER [RemoveLC]
GO



