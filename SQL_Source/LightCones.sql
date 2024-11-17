USE [HSRDB]
GO
CREATE TABLE [dbo].[LightCones](
    [Concept] [nvarchar](50) NOT NULL,
	[Rairty] [int] NOT NULL,
	[Path] [nvarchar](20) NOT NULL,
	[Level] [int] NOT NULL,
	[SuperimposeLevel] [int] NOT NULL,
	[HP] decimal(6,2) NOT NULL,
	[ATK] decimal(6,2) NOT NULL,
	[DEF] decimal(6,2) NOT NULL,
	[LCBoostPercentage1] [nvarchar](20) NULL,
	[LCBoostPercentageValue1] decimal(8, 4) NULL,
	[LCBoostPercentage2] [nvarchar](20) NULL,
	[LCBoostPercentageValue2] decimal(8, 4) NULL,
	[Skill] [nvarchar](500) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Concept] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO