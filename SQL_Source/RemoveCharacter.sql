USE [HSRDB]
GO

CREATE TRIGGER [dbo].[RemoveCharacter] ON [dbo].[Equipped]
AFTER DELETE 
AS
BEGIN
	SET NOCOUNT ON;
	UPDATE Relics
	SET Equipped=NULL WHERE EXISTS(SELECT * FROM deleted WHERE ID=Head OR ID=Hands OR ID=Body OR ID=Feet OR ID=PlanarSphere OR ID=LinkRope);
End
GO

ALTER TABLE [dbo].[Equipped] ENABLE TRIGGER [RemoveCharacter]
GO

