USE [HSRDB]
GO

CREATE TRIGGER [dbo].[LimitRelics] ON [dbo].[Relics]
INSTEAD OF INSERT
AS
BEGIN
	SET NOCOUNT ON;
	DECLARE @InsertNum int;
	DECLARE @CurrentNum int;
	SELECT @InsertNum = COUNT(*) FROM inserted

	SELECT @CurrentNum = COUNT(*) FROM Relics
	IF (@InsertNum + @CurrentNum) <= 2000
		BEGIN
			INSERT INTO Relics
			SELECT  * FROM inserted
		END
	ELSE
		BEGIN
			PRINT('The total number of relics cannot be more than 2000.')
			ROLLBACK TRANSACTION
		END
END
GO
ALTER TABLE [dbo].[Relics] ENABLE TRIGGER [LimitRelics]
GO

