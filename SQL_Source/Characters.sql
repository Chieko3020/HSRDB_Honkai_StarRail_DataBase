USE [HSRDB]
GO
CREATE TABLE [dbo].[Characters](
	[Concept] [nvarchar](50) NOT NULL,
	[Faction] [nvarchar](50) NOT NULL,
	[Rairty] [int] NOT NULL,
	[Path] [nvarchar](20) NOT NULL,
	[Combat] [nvarchar](10) NOT NULL,
	[Level] [int] NOT NULL,
	[Eidolons] [int] NOT NULL,
	[HP] decimal(6,2) NOT NULL,
	[ATK] decimal(6,2) NOT NULL,
	[DEF] decimal(6,2) NOT NULL,
	[SPD] decimal(6,2) NOT NULL,
	[Energy] [int] NOT NULL,
	[TraceBoostPercentage1] [nvarchar](20) NOT NULL,
	[TraceBoostPercentageValue1] decimal(8, 4) NULL,
	[TraceBoostPercentage2] [nvarchar](20) NOT NULL,
	[TraceBoostPercentageValue2] decimal(8, 4) NULL,
	[TraceBoostPercentage3] [nvarchar](20) NOT NULL,
	[TraceBoostPercentageValue3] decimal(8, 4) NULL,
	[TraceBoostSPDValue] [smallint] NULL,
PRIMARY KEY CLUSTERED 
(
	[Concept] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO	

