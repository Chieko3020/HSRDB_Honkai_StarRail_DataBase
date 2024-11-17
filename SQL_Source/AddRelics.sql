USE [HSRDB]
GO

CREATE TRIGGER [dbo].[AddRelics] ON [dbo].[Relics]
AFTER UPDATE
AS
BEGIN
IF UPDATE(Equipped) AND EXISTS(SELECT Equipped FROM inserted WHERE inserted.Equipped IS NOT NULL)
BEGIN
	SET NOCOUNT ON;
	DECLARE @ID smallint;
	DECLARE @Slot nvarchar(20);
	DECLARE @MainStat nvarchar(20);
	DECLARE @MSValue decimal(8, 4);
	DECLARE @SubStat_1 nvarchar(20);
	DECLARE @SSValue_1 decimal(8, 4);
	DECLARE @SubStat_2 nvarchar(20);
	DECLARE @SSValue_2 decimal(8, 4);
	DECLARE @SubStat_3 nvarchar(20);
	DECLARE @SSValue_3 decimal(8, 4);
	DECLARE @SubStat_4 nvarchar(20);
	DECLARE @SSValue_4 decimal(8, 4);
	DECLARE @Equipped nvarchar(50);
	SELECT @ID=ID FROM inserted
	SELECT @Equipped=Equipped FROM inserted
	SELECT @Slot=Slot FROM inserted
	SELECT @MainStat=MainStat FROM inserted
	SELECT @MSValue=MSValue FROM inserted
	SELECT @SubStat_1=SubStat_1 FROM inserted
	SELECT @SSValue_1=SSValue_1 FROM inserted
	SELECT @SubStat_2=SubStat_2 FROM inserted
	SELECT @SSValue_2=SSValue_2 FROM inserted
	SELECT @SubStat_3=SubStat_3 FROM inserted
	SELECT @SSValue_3=SSValue_3 FROM inserted
	SELECT @SubStat_4=SubStat_4 FROM inserted
	SELECT @SSValue_4=SSValue_4 FROM inserted
	IF(@Equipped IS NOT NULL)
	BEGIN
		IF(@Slot='Head')
		BEGIN
			UPDATE Equipped
			SET Equipped.Head=@ID WHERE Equipped.Concept=@Equipped;
		END
		ELSE IF(@Slot='Hands')
		BEGIN
			UPDATE Equipped
			SET Equipped.Hands=@ID WHERE Equipped.Concept=@Equipped;
		END
		ELSE IF(@Slot='Body')
		BEGIN
			UPDATE Equipped
			SET Equipped.Body=@ID WHERE Equipped.Concept=@Equipped;
		END
		ELSE IF(@Slot='Feet')
		BEGIN
			UPDATE Equipped
			SET Equipped.Feet=@ID WHERE Equipped.Concept=@Equipped;
		END
		ELSE IF(@Slot='PlanarSphere')
		BEGIN
			UPDATE Equipped
			SET Equipped.PlanarSphere=@ID WHERE Equipped.Concept=@Equipped;
		END
		ELSE IF(@Slot='LinkRope')
		BEGIN
			UPDATE Equipped
			SET Equipped.LinkRope=@ID WHERE Equipped.Concept=@Equipped;
		END
	END
	IF(@Equipped IS NOT NULL)
	BEGIN
		 IF(@MainStat='HPBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.HPBoost=Equipped.HPBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='ATKBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.ATKBoost=Equipped.ATKBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='CritRate')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.CritRate=Equipped.CritRate+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='CritDMG')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.CritDMG=Equipped.CritDMG+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='BreakEffect')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.BreakEffect=Equipped.BreakEffect+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='OutgoingHealingBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.OutgoingHealingBoost=Equipped.OutgoingHealingBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='EnergyRegenerationRate')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.EnergyRegenerationRate=Equipped.EnergyRegenerationRate+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='EffectHitRate')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.EffectHitRate=Equipped.EffectHitRate+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='HPBoostPercentage')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.HPBoostPercentage=Equipped.HPBoostPercentage+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='ATKBoostPercentage')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.ATKBoostPercentage=Equipped.ATKBoostPercentage+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='DEFBoostPercentage')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.DEFBoostPercentage=Equipped.DEFBoostPercentage+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='SPDBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.SPDBoost=Equipped.SPDBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='PhysicalDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.PhysicalDMGBoost=Equipped.PhysicalDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='FireDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.FireDMGBoost=Equipped.FireDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='IceDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.IceDMGBoost=Equipped.IceDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='LightningDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.LightningDMGBoost=Equipped.LightningDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='WindDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.WindDMGBoost=Equipped.WindDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='QuantumDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.QuantumDMGBoost=Equipped.QuantumDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@MainStat='ImaginaryDMGBoost')
		 BEGIN
		 	  UPDATE Equipped
			  SET Equipped.ImaginaryDMGBoost=Equipped.ImaginaryDMGBoost+@MSValue WHERE Equipped.Concept=@Equipped;
		 END
	END
	IF(@Equipped IS NOT NULL)
	BEGIN
		 IF(@SubStat_1='CritRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritRate=Equipped.CritRate+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='CritRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritRate=Equipped.CritRate+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='CritRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritRate=Equipped.CritRate+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='CritRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritRate=Equipped.CritRate+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='CritDMG')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritDMG=Equipped.CritDMG+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='CritDMG')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritDMG=Equipped.CritDMG+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='CritDMG')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritDMG=Equipped.CritDMG+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='CritDMG')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.CritDMG=Equipped.CritDMG+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='BreakEffect')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.BreakEffect=Equipped.BreakEffect+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='BreakEffect')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.BreakEffect=Equipped.BreakEffect+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='BreakEffect')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.BreakEffect=Equipped.BreakEffect+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='BreakEffect')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.BreakEffect=Equipped.BreakEffect+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='EffectHitRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectHitRate=Equipped.EffectHitRate+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='EffectHitRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectHitRate=Equipped.EffectHitRate+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='EffectHitRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectHitRate=Equipped.EffectHitRate+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='EffectHitRate')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectHitRate=Equipped.EffectHitRate+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='EffectRES')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectRES=Equipped.EffectRES+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='EffectRES')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectRES=Equipped.EffectRES+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='EffectRES')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectRES=Equipped.EffectRES+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='EffectRES')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.EffectRES=Equipped.EffectRES+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='HPBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoost=Equipped.HPBoost+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='HPBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoost=Equipped.HPBoost+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='HPBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoost=Equipped.HPBoost+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='HPBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoost=Equipped.HPBoost+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='ATKBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoost=Equipped.ATKBoost+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='ATKBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoost=Equipped.ATKBoost+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='ATKBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoost=Equipped.ATKBoost+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='ATKBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoost=Equipped.ATKBoost+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='DEFBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoost=Equipped.DEFBoost+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='DEFBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoost=Equipped.DEFBoost+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='DEFBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoost=Equipped.DEFBoost+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='DEFBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoost=Equipped.DEFBoost+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='SPDBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.SPDBoost=Equipped.SPDBoost+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='SPDBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.SPDBoost=Equipped.SPDBoost+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='SPDBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.SPDBoost=Equipped.SPDBoost+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='SPDBoost')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.SPDBoost=Equipped.SPDBoost+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='HPBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoostPercentage=Equipped.HPBoostPercentage+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='HPBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoostPercentage=Equipped.HPBoostPercentage+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='HPBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoostPercentage=Equipped.HPBoostPercentage+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='HPBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.HPBoostPercentage=Equipped.HPBoostPercentage+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='ATKBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoostPercentage=Equipped.ATKBoostPercentage+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='ATKBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoostPercentage=Equipped.ATKBoostPercentage+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='ATKBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoostPercentage=Equipped.ATKBoostPercentage+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='ATKBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.ATKBoostPercentage=Equipped.ATKBoostPercentage+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
		 IF(@SubStat_1='DEFBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoostPercentage=Equipped.DEFBoostPercentage+@SSValue_1 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_2='DEFBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoostPercentage=Equipped.DEFBoostPercentage+@SSValue_2 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_3='DEFBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoostPercentage=Equipped.DEFBoostPercentage+@SSValue_3 WHERE Equipped.Concept=@Equipped;
		 END
		 ELSE IF(@SubStat_4='DEFBoostPercentage')
		 BEGIN
			  UPDATE Equipped
			  SET Equipped.DEFBoostPercentage=Equipped.DEFBoostPercentage+@SSValue_4 WHERE Equipped.Concept=@Equipped;
		 END
	 END
	IF(@Equipped IS NOT NULL)
	BEGIN
	 DECLARE @HeadSet nvarchar(50);
	 DECLARE @HandsSet nvarchar(50);
	 DECLARE @BodySet nvarchar(50);
	 DECLARE @FeetSet nvarchar(50);
	 DECLARE @PlanarSphereSet nvarchar(50);
	 DECLARE @LinkRopeSet nvarchar(50);
	 DECLARE @RelicSet2pc1 nvarchar(50);
	 DECLARE @RelicSet2pc2 nvarchar(50);
	 DECLARE @RelicSet4pc  nvarchar(50);
	 DECLARE @PlanarOrnamentsSet2pc nvarchar(50);
	 DECLARE @CritRate decimal(8, 4)=0;
	 DECLARE @CritDMG decimal(8, 4)=0;
	 DECLARE @BreakEffect decimal(8, 4)=0;
	 DECLARE @OutgoingHealingBoost decimal(8, 4)=0;
	 DECLARE @EnergyRegenerationRate decimal(8, 4)=0;
	 DECLARE @EffectHitRate decimal(8, 4)=0;
	 DECLARE @EffectRES decimal(8, 4)=0;
	 DECLARE @HPBoostPercentage decimal(8, 4)=0;
	 DECLARE @ATKBoostPercentage decimal(8, 4)=0;
	 DECLARE @DEFBoostPercentage decimal(8, 4)=0;
	 DECLARE @SPDBoostPercentage decimal(8, 4)=0;
	 DECLARE @PhysicalDMGBoost decimal(8, 4)=0;
	 DECLARE @FireDMGBoost decimal(8, 4)=0;
	 DECLARE @IceDMGBoost decimal(8, 4)=0;
	 DECLARE @LightningDMGBoost decimal(8, 4)=0;
	 DECLARE @WindDMGBoost decimal(8, 4)=0;
	 DECLARE @QuantumDMGBoost decimal(8, 4)=0;
	 DECLARE @ImaginaryDMGBoost decimal(8, 4)=0;
	 SELECT @HeadSet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.Head FROM Equipped WHERE Equipped.Concept=@Equipped)
	 SELECT @HandsSet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.Hands FROM Equipped WHERE Equipped.Concept=@Equipped)
	 SELECT @BodySet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.Body FROM Equipped WHERE Equipped.Concept=@Equipped)
	 SELECT @FeetSet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.Feet FROM Equipped WHERE Equipped.Concept=@Equipped)
	 SELECT @PlanarSphereSet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.PlanarSphere FROM Equipped WHERE Equipped.Concept=@Equipped)
	 SELECT @LinkRopeSet=Relics.Concept FROM Relics WHERE Relics.ID=(SELECT Equipped.LinkRope FROM Equipped WHERE Equipped.Concept=@Equipped)
	 IF(@HeadSet=@HandsSet AND @HeadSet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@HeadSet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@HeadSet;
		END
		ELSE IF(@BodySet=@FeetSet AND @BodySet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@BodySet;
		END
	 END
	 ELSE IF(@HeadSet=@BodySet AND @HeadSet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@HeadSet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@HeadSet;
		END
		ELSE IF(@HandsSet=@FeetSet AND @HandsSet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@HandsSet;
		END
	 END
	 ELSE IF(@HeadSet=@FeetSet AND @HeadSet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@HeadSet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@HeadSet;
		END
		ELSE IF(@HandsSet=@BodySet AND @HandsSet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@HandsSet;
		END
	 END
	 ELSE IF(@HandsSet=@BodySet AND @HandsSet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@HandsSet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@HandsSet;
		END
		ELSE IF(@HeadSet=@FeetSet AND @HeadSet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@HeadSet;
		END
	 END
	 ELSE IF(@HandsSet=@FeetSet AND @HandsSet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@HandsSet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@HandsSet;
		END
		ELSE IF(@HeadSet=@BodySet AND @HeadSet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@HeadSet;
		END
	 END
	 ELSE IF(@BodySet=@FeetSet AND @BodySet IS NOT NULL)
	 BEGIN
		SET @RelicSet2pc1=@BodySet;
		IF(@HeadSet=@HandsSet AND @HandsSet=@BodySet AND @BodySet=@FeetSet)
		BEGIN
			SET @RelicSet4pc=@BodySet;
		END
		ELSE IF(@HeadSet=@HandsSet AND @HeadSet IS NOT NULL)
		BEGIN
			SET @RelicSet2pc2=@HeadSet;
		END
	 END
	 IF(@PlanarSphereSet=@LinkRopeSet AND @PlanarSphereSet IS NOT NULL)
	 BEGIN
		SET @PlanarOrnamentsSet2pc=@PlanarSphereSet;
	 END
	 IF(@RelicSet2pc1 IS NOT NULL)
	 BEGIN
		IF(@RelicSet2pc1='Thief of Shooting Meteor' OR @RelicSet2pc1='Watchmaker, Master of Dream Machinations' OR @RelicSet2pc1='Iron Cavalry Against the Scourge')
		  BEGIN
			   SET @BreakEffect=@BreakEffect+0.16;
		  END
		  ELSE IF(@RelicSet2pc1='Passerby of Wandering Cloud')
		  BEGIN
			   SET @OutgoingHealingBoost=@OutgoingHealingBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Longevous Disciple')
		  BEGIN
			   SET @HPBoostPercentage=@HPBoostPercentage+0.12;
		  END
		  ELSE IF(@RelicSet2pc1='Musketeer of Wild Wheat' OR @RelicSet2pc1='Prisoner in Deep Confinement' OR @RelicSet2pc1='The Wind-Soaring Valorous')
		  BEGIN
			   SET @ATKBoostPercentage=@ATKBoostPercentage+0.12;
		  END
		  ELSE IF(@RelicSet2pc1='Knight of Purity Palace')
		  BEGIN
			   SET @DEFBoostPercentage=@DEFBoostPercentage+0.15;
		  END
		  ELSE IF(@RelicSet2pc1='Messenger Traversing Hackerspace')
		  BEGIN
			   SET @SPDBoostPercentage=@SPDBoostPercentage+0.06;
		  END
		  ELSE IF(@RelicSet2pc1='Champion of Streetwise Boxing')
		  BEGIN
			   SET @PhysicalDMGBoost=@PhysicalDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Firesmith of Lava-Forging')
		  BEGIN
			   SET @FireDMGBoost=@FireDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Hunter of Glacial Forest')
		  BEGIN
			   SET @IceDMGBoost=@IceDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Band of Sizzling Thunder')
		  BEGIN
			   SET @LightningDMGBoost=@LightningDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Eagle of Twilight Line')
		  BEGIN
			   SET @WindDMGBoost=@WindDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Genius of Brilliant Stars')
		  BEGIN
			   SET @QuantumDMGBoost=@QuantumDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc1='Wastelander of Banditry Desert')
		  BEGIN
			   SET @ImaginaryDMGBoost=@ImaginaryDMGBoost+0.1;
		  END
	 END
	 IF(@RelicSet2pc2 IS NOT NULL)
	 BEGIN
		IF(@RelicSet2pc2='Thief of Shooting Meteor' OR @RelicSet2pc2='Watchmaker, Master of Dream Machinations' OR @RelicSet2pc2='Iron Cavalry Against the Scourge')
		  BEGIN
			   SET @BreakEffect=@BreakEffect+0.16;
		  END
		  ELSE IF(@RelicSet2pc2='Passerby of Wandering Cloud')
		  BEGIN
			   SET @OutgoingHealingBoost=@OutgoingHealingBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Longevous Disciple')
		  BEGIN
			   SET @HPBoostPercentage=@HPBoostPercentage+0.12;
		  END
		  ELSE IF(@RelicSet2pc2='Musketeer of Wild Wheat' OR @RelicSet2pc2='Prisoner in Deep Confinement' OR @RelicSet2pc2='The Wind-Soaring Valorous')
		  BEGIN
			   SET @ATKBoostPercentage=@ATKBoostPercentage+0.12;
		  END
		  ELSE IF(@RelicSet2pc2='Knight of Purity Palace')
		  BEGIN
			   SET @DEFBoostPercentage=@DEFBoostPercentage+0.15;
		  END
		  ELSE IF(@RelicSet2pc2='Messenger Traversing Hackerspace')
		  BEGIN
			   SET @SPDBoostPercentage=@SPDBoostPercentage+0.06;
		  END
		  ELSE IF(@RelicSet2pc2='Champion of Streetwise Boxing')
		  BEGIN
			   SET @PhysicalDMGBoost=@PhysicalDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Firesmith of Lava-Forging')
		  BEGIN
			   SET @FireDMGBoost=@FireDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Hunter of Glacial Forest')
		  BEGIN
			   SET @IceDMGBoost=@IceDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Band of Sizzling Thunder')
		  BEGIN
			   SET @LightningDMGBoost=@LightningDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Eagle of Twilight Line')
		  BEGIN
			   SET @WindDMGBoost=@WindDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Genius of Brilliant Stars')
		  BEGIN
			   SET @QuantumDMGBoost=@QuantumDMGBoost+0.1;
		  END
		  ELSE IF(@RelicSet2pc2='Wastelander of Banditry Desert')
		  BEGIN
			   SET @ImaginaryDMGBoost=@ImaginaryDMGBoost+0.1;
		  END
	 END
	 IF(@RelicSet4pc IS NOT NULL)
	 BEGIN
		IF(@RelicSet4pc='Musketeer of Wild Wheat')
		   BEGIN
				SET @SPDBoostPercentage=@SPDBoostPercentage+0.06;
		   END
		   ELSE IF(@RelicSet4pc='Thief of Shooting Meteor')
		   BEGIN
				SET @BreakEffect=@BreakEffect+0.16;
		   END
		   ELSE IF(@RelicSet4pc='Pioneer Diver of Dead Waters')
		   BEGIN
				SET @CritRate=@CritRate+0.04;
		   END
		   ELSE IF(@RelicSet4pc='The Wind-Soaring Valorous')
		   BEGIN
				SET @CritRate=@CritRate+0.06;
		   END
	 END
	 IF(@PlanarOrnamentsSet2pc IS NOT NULL)
	 BEGIN
		IF(@PlanarOrnamentsSet2pc='Space Sealing Station')
		  BEGIN
			   SET @ATKBoostPercentage=@ATKBoostPercentage+0.12;
			   IF(EXISTS (SELECT SPD,SPDBoost,SPDBoostPercentage FROM Equipped WHERE Equipped.Concept=@Equipped AND SPD+SPDBoost+SPD*(SPDBoostPercentage+@SPDBoostPercentage)>=120))
			   BEGIN
				SET @ATKBoostPercentage=@ATKBoostPercentage+0.12; 
			   END
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Fleet of the Ageless')
		  BEGIN
			   SET @HPBoostPercentage=@HPBoostPercentage+0.12;
			   IF(EXISTS (SELECT SPD,SPDBoost,SPDBoostPercentage FROM Equipped WHERE Equipped.Concept=@Equipped AND SPD+SPDBoost+SPD*(SPDBoostPercentage+@SPDBoostPercentage)>=120))
			   BEGIN
				SET @ATKBoostPercentage=@ATKBoostPercentage+0.08;
			   END
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Pan-Cosmic Commercial Enterprise')
		  BEGIN
			   SET @EffectHitRate=@EffectHitRate+0.1;
			   IF(EXISTS(SELECT EffectHitRate FROM Equipped WHERE Equipped.Concept=@Equipped AND EffectHitRate+@EffectHitRate<=1))
			   BEGIN
				DECLARE @EHR real;
				SELECT @EHR=EffectHitRate+@EffectHitRate FROM Equipped WHERE Equipped.Concept=@Equipped ;
			        SET @ATKBoostPercentage=@ATKBoostPercentage+(@EHR)*0.25;
			   END
			   ELSE IF(EXISTS(SELECT EffectHitRate FROM Equipped WHERE Equipped.Concept=@Equipped AND EffectHitRate+@EffectHitRate>1))
			   BEGIN
			        SET @ATKBoostPercentage=@ATKBoostPercentage+0.25;
			   END
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Belobog of the Architects')
		  BEGIN
			   SET @DEFBoostPercentage=@DEFBoostPercentage+0.15;
			   IF(EXISTS(SELECT EffectHitRate FROM Equipped WHERE Equipped.Concept=@Equipped AND EffectHitRate>=0.5))
			   BEGIN
				SET @DEFBoostPercentage=@DEFBoostPercentage+0.15;
			   END
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Celestial Differentiator')
		  BEGIN
			   SET @CritDMG=@CritDMG+0.16;
		  END
		  ELSE IF(@PlanarSphereSet='Inert Salsotto')
		  BEGIN
			   SET @CritRate=@CritRate+0.08 ;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Talia Kingdom of Banditry')
		  BEGIN
			   SET @BreakEffect=@BreakEffect+0.16;
			   IF(EXISTS(SELECT SPD,SPDBoost,SPDBoostPercentage FROM Equipped WHERE Equipped.Concept=@Equipped AND SPD+SPDBoost+SPD*(SPDBoostPercentage+@SPDBoostPercentage)>=145))
			   BEGIN
				SET @BreakEffect=@BreakEffect+0.20;
			   END  
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Sprightly Vonwacq')
		  BEGIN
			   SET @EnergyRegenerationRate=@EnergyRegenerationRate+0.05;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Rutilant Arena')
		  BEGIN
			   SET @CritRate=@CritRate+0.08;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Broken Keel')
		  BEGIN
			   SET @EffectRES=@EffectRES+0.1;
			   IF(EXISTS(SELECT EffectRES FROM Equipped WHERE Equipped.Concept=@Equipped AND EffectRES+@EffectRES>=0.3))
			   BEGIN
				SET @CritDMG=@CritDMG+0.1;
			   END   
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Firmament Frontline Glamoth')
		  BEGIN
			   SET @ATKBoostPercentage=@ATKBoostPercentage+0.12;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Penacony, Land of the Dreams')
		  BEGIN
			   SET @EnergyRegenerationRate=@EnergyRegenerationRate+0.05;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Sigonia, the Unclaimed Desolation')
		  BEGIN
			   SET @CritRate=@CritRate+0.04;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Izumo Gensei and Takama Divine Realm')
		  BEGIN
			   SET @ATKBoostPercentage=@ATKBoostPercentage+0.12;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Forge of the Kalpagni Lantern')
		  BEGIN
			   SET @SPDBoostPercentage=@SPDBoostPercentage+0.06;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='Lushaka, the Sunken Seas')
		  BEGIN
			   SET @EnergyRegenerationRate=@EnergyRegenerationRate+0.05;
		  END
		  ELSE IF(@PlanarOrnamentsSet2pc='The Wondrous BananAmusement Park')
		  BEGIN
			   SET @CritDMG=@CritDMG+0.16;
		  END
	 END
	UPDATE Equipped SET Equipped.SetCritRate=@CritRate WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetCritDMG=@CritDMG WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetBreakEffect=@BreakEffect WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetOutgoingHealingBoost=@OutgoingHealingBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetEnergyRegenerationRate=@EnergyRegenerationRate WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetEffectHitRate=@EffectHitRate WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetEffectRES=@EffectRES WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetHPBoostPercentage=@HPBoostPercentage WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetATKBoostPercentage=@ATKBoostPercentage WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetDEFBoostPercentage=@DEFBoostPercentage WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetSPDBoostPercentage=@SPDBoostPercentage WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetPhysicalDMGBoost=@PhysicalDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetFireDMGBoost=@FireDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetIceDMGBoost=@IceDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetLightningDMGBoost=@LightningDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetWindDMGBoost=@WindDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetQuantumDMGBoost=@QuantumDMGBoost WHERE Equipped.Concept=@Equipped;
	UPDATE Equipped SET Equipped.SetImaginaryDMGBoost=@ImaginaryDMGBoost WHERE Equipped.Concept=@Equipped;
   END
END
END
GO

ALTER TABLE [dbo].[Relics] ENABLE TRIGGER [AddRelics]
GO

