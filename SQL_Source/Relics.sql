USE [HSRDB]
GO
CREATE FUNCTION ID()
	RETURNS int
	AS
   	BEGIN
		DECLARE @ID int=1
		WHILE EXISTS(SELECT Concept FROM Relics WHERE Relics.ID=@ID AND Concept IS NOT NULL)
		BEGIN
			SET @ID=@ID+1
		END
		RETURN(@ID)
    END
GO

CREATE TABLE [dbo].[Relics](
	[ID] [smallint] NOT NULL DEFAULT dbo.ID(),
	[Concept] [nvarchar](50) NOT NULL,
	[Slot] [nvarchar](20) NOT NULL,
	[SlotName] [nvarchar](50) NOT NULL,
	[RelicLevel] [smallint] NOT NULL,
	[MainStat] [nvarchar](20) NOT NULL,
	[MSValue] decimal(8, 4) NOT NULL,
	[SubStat_1] [nvarchar](20) NULL,
	[SSValue_1] decimal(8, 4) NULL,
	[SubStat_2] [nvarchar](20) NULL,
	[SSValue_2] decimal(8, 4) NULL,
	[SubStat_3] [nvarchar](20) NULL,
	[SSValue_3] decimal(8, 4) NULL,
	[SubStat_4] [nvarchar](20) NULL,
	[SSValue_4] decimal(8, 4) NULL,
	[Equipped] [nvarchar](50) NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO