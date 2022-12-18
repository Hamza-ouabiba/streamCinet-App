

/*==============================================================*/
/* Table : CATEGORY                                             */
/*==============================================================*/
create table CATEGORY (
   ID_CATEGORY          int        identity(1,1)   not null,
   CATEGORY             varchar(50)          not null,
   constraint PK_CATEGORY primary key (ID_CATEGORY)
)
go

/*==============================================================*/
/* Table : EPISODE                                              */
/*==============================================================*/
create table EPISODE (
   ID_EPISODE           int         identity(1,1)         not null,
   ID_SEASON            int                  not null,
   NUMBER               int                  not null,
   DATE                 datetime             not null,
   TITLE                varchar(50)          not null,
   ID_API               int                  not null,
   constraint PK_EPISODE primary key (ID_EPISODE)
)
go

/*==============================================================*/
/* Index : ASSOCIATION_6_FK                                     */
/*==============================================================*/




create nonclustered index ASSOCIATION_6_FK on EPISODE (ID_SEASON ASC)
go

/*==============================================================*/
/* Table : MOVIE                                                */
/*==============================================================*/
create table MOVIE (
   ID_MOVIE             int        identity(1,1)          not null,
   ID_API               int                  not null,
   TITLE                varchar(50)          not null,
   OVERVIEW             text                 not null,
   RATING               float                not null,
   RELEASE_DATE         datetime             not null,
   POSTER               image                not null,
   BACKDROP             image                not null,
   constraint PK_MOVIE primary key (ID_MOVIE)
)
go

/*==============================================================*/
/* Table : MOVIECATEGORY                                        */
/*==============================================================*/
create table MOVIECATEGORY (
   ID_MOVIE             int                  not null,
   ID_CATEGORY          int                  not null,
   constraint PK_MOVIECATEGORY primary key (ID_MOVIE, ID_CATEGORY)
)
go

/*==============================================================*/
/* Index : MOVIECATEGORY_FK                                     */
/*==============================================================*/




create nonclustered index MOVIECATEGORY_FK on MOVIECATEGORY (ID_MOVIE ASC)
go

/*==============================================================*/
/* Index : MOVIECATEGORY2_FK                                    */
/*==============================================================*/




create nonclustered index MOVIECATEGORY2_FK on MOVIECATEGORY (ID_CATEGORY ASC)
go

/*==============================================================*/
/* Table : PLANNING                                             */
/*==============================================================*/
create table PLANNING (
   ID                   int         identity(1,1)         not null,
   DATE                 datetime     unique        not null,
   constraint PK_PLANNING primary key (ID)
)
go

/*==============================================================*/
/* Table : PLANNING_MOVIE                                       */
/*==============================================================*/
create table PLANNING_MOVIE (
   ID                   int                  not null,
   ID_MOVIE             int                  not null,
   constraint PK_PLANNING_MOVIE primary key (ID, ID_MOVIE)
)
go

/*==============================================================*/
/* Index : PLANNING_MOVIE_FK                                    */
/*==============================================================*/




create nonclustered index PLANNING_MOVIE_FK on PLANNING_MOVIE (ID ASC)
go

/*==============================================================*/
/* Index : PLANNING_MOVIE2_FK                                   */
/*==============================================================*/




create nonclustered index PLANNING_MOVIE2_FK on PLANNING_MOVIE (ID_MOVIE ASC)
go

/*==============================================================*/
/* Table : PLANNING_SERIE                                       */
/*==============================================================*/
create table PLANNING_SERIE (
   ID                   int                  not null,
   ID_SERIE             int                  not null,
   constraint PK_PLANNING_SERIE primary key (ID, ID_SERIE)
)
go

/*==============================================================*/
/* Index : PLANNING_SERIE_FK                                    */
/*==============================================================*/




create nonclustered index PLANNING_SERIE_FK on PLANNING_SERIE (ID ASC)
go

/*==============================================================*/
/* Index : PLANNING_SERIE2_FK                                   */
/*==============================================================*/




create nonclustered index PLANNING_SERIE2_FK on PLANNING_SERIE (ID_SERIE ASC)
go

/*==============================================================*/
/* Table : SEASON                                               */
/*==============================================================*/
create table SEASON (
   ID_SEASON            int        identity(1,1)          not null,
   ID_SERIE             int                  not null,
   NUMBER               int                  not null,
   ID_API               int                  not null,
   constraint PK_SEASON primary key (ID_SEASON)
)
go

/*==============================================================*/
/* Index : ASSOCIATION_7_FK                                     */
/*==============================================================*/




create nonclustered index ASSOCIATION_7_FK on SEASON (ID_SERIE ASC)
go

/*==============================================================*/
/* Table : SERIE                                                */
/*==============================================================*/
create table SERIE (
   ID_SERIE             int        identity(1,1)          not null,
   ID_API               int                  not null,
   TITLE                varchar(50)          not null,
   OVERVIEW             text                 not null,
   POSTER               image                not null,
   BACKDROP             image                not null,
   RELEASE_DATE         datetime             not null,
   RATING               float                not null,
   COUNTRY              varchar(50)          not null,
   constraint PK_SERIE primary key (ID_SERIE)
)
go

/*==============================================================*/
/* Table : SERIECATEGORY                                        */
/*==============================================================*/
create table SERIECATEGORY (
   ID_CATEGORY          int                 not null,
   ID_SERIE             int                  not null,
   constraint PK_SERIECATEGORY primary key (ID_CATEGORY, ID_SERIE)
)
go

/*==============================================================*/
/* Index : SERIECATEGORY_FK                                     */
/*==============================================================*/




create nonclustered index SERIECATEGORY_FK on SERIECATEGORY (ID_CATEGORY ASC)
go

/*==============================================================*/
/* Index : SERIECATEGORY2_FK                                    */
/*==============================================================*/




create nonclustered index SERIECATEGORY2_FK on SERIECATEGORY (ID_SERIE ASC)
go

/*==============================================================*/
/* Table : "USER"                                               */
/*==============================================================*/
create table "USER" (
   ID_USER              int         identity(1,1)         not null,
   ID_WATCH_LIST        int                  null,
   PASSWORD             varchar(30)          not null,
   NAME                 varchar(30)          not null,
   EMAIL                varchar(50)          not null,
   constraint PK_USER primary key (ID_USER)
)
go

/*==============================================================*/
/* Index : BELONGS_FK                                           */
/*==============================================================*/




create nonclustered index BELONGS_FK on "USER" (ID_WATCH_LIST ASC)
go

/*==============================================================*/
/* Table : WATCHLIST                                            */
/*==============================================================*/
create table WATCHLIST (
   ID_WATCH_LIST        int     identity(1,1)     not null,
   ID_USER              int                  not null,
   NAME                 varchar(30)          null,
   constraint PK_WATCHLIST primary key (ID_WATCH_LIST)
)
go

/*==============================================================*/
/* Index : BELONGS2_FK                                          */
/*==============================================================*/




create nonclustered index BELONGS2_FK on WATCHLIST (ID_USER ASC)
go

/*==============================================================*/
/* Table : WATCHLIST_MOVIE                                      */
/*==============================================================*/
create table WATCHLIST_MOVIE (
   ID_MOVIE             int                  not null,
   ID_WATCH_LIST        int                  not null,
   constraint PK_WATCHLIST_MOVIE primary key (ID_MOVIE, ID_WATCH_LIST)
)
go

/*==============================================================*/
/* Index : WATCHLIST_MOVIE_FK                                   */
/*==============================================================*/




create nonclustered index WATCHLIST_MOVIE_FK on WATCHLIST_MOVIE (ID_MOVIE ASC)
go

/*==============================================================*/
/* Index : WATCHLIST_MOVIE2_FK                                  */
/*==============================================================*/




create nonclustered index WATCHLIST_MOVIE2_FK on WATCHLIST_MOVIE (ID_WATCH_LIST ASC)
go

/*==============================================================*/
/* Table : WATCHLIST_SERIE                                      */
/*==============================================================*/
create table WATCHLIST_SERIE (
   ID_WATCH_LIST        int                  not null,
   ID_SERIE             int                  not null,
   constraint PK_WATCHLIST_SERIE primary key (ID_WATCH_LIST, ID_SERIE)
)
go

/*==============================================================*/
/* Index : WATCHLIST_SERIE_FK                                   */
/*==============================================================*/




create nonclustered index WATCHLIST_SERIE_FK on WATCHLIST_SERIE (ID_WATCH_LIST ASC)
go

/*==============================================================*/
/* Index : WATCHLIST_SERIE2_FK                                  */
/*==============================================================*/




create nonclustered index WATCHLIST_SERIE2_FK on WATCHLIST_SERIE (ID_SERIE ASC)
go

alter table EPISODE
   add constraint FK_EPISODE_ASSOCIATI_SEASON foreign key (ID_SEASON)
      references SEASON (ID_SEASON)
go

alter table MOVIECATEGORY
   add constraint FK_MOVIECAT_MOVIECATE_MOVIE foreign key (ID_MOVIE)
      references MOVIE (ID_MOVIE)
go

alter table MOVIECATEGORY
   add constraint FK_MOVIECAT_MOVIECATE_CATEGORY foreign key (ID_CATEGORY)
      references CATEGORY (ID_CATEGORY)
go

alter table PLANNING_MOVIE
   add constraint FK_PLANNING_PLANNINGM_PLANNING foreign key (ID)
      references PLANNING (ID)
go

alter table PLANNING_MOVIE
   add constraint FK_PLANNING_PLANNING__MOVIE foreign key (ID_MOVIE)
      references MOVIE (ID_MOVIE)
go

alter table PLANNING_SERIE
   add constraint FK_PLANNING_PLANNINGS_PLANNING foreign key (ID)
      references PLANNING (ID)
go

alter table PLANNING_SERIE
   add constraint FK_PLANNING_PLANNING__SERIE foreign key (ID_SERIE)
      references SERIE (ID_SERIE)
go

alter table SEASON
   add constraint FK_SEASON_ASSOCIATI_SERIE foreign key (ID_SERIE)
      references SERIE (ID_SERIE)
go

alter table SERIECATEGORY
   add constraint FK_SERIECAT_SERIECATE_CATEGORY foreign key (ID_CATEGORY)
      references CATEGORY (ID_CATEGORY)
go

alter table SERIECATEGORY
   add constraint FK_SERIECAT_SERIECATE_SERIE foreign key (ID_SERIE)
      references SERIE (ID_SERIE)
go

alter table "USER"
   add constraint FK_USER_BELONGS_WATCHLIS foreign key (ID_WATCH_LIST)
      references WATCHLIST (ID_WATCH_LIST)
go

alter table WATCHLIST
   add constraint FK_WATCHLIS_BELONGS2_USER foreign key (ID_USER)
      references "USER" (ID_USER)
go

alter table WATCHLIST_MOVIE
   add constraint FK_WATCHLIS_WATCHLIST_WATCHLIS2 foreign key (ID_WATCH_LIST)
      references WATCHLIST (ID_WATCH_LIST)
go

alter table WATCHLIST_MOVIE
   add constraint FK_WATCHLIS_WATCHLIST_MOVIE foreign key (ID_MOVIE)
      references MOVIE (ID_MOVIE)
go

alter table WATCHLIST_SERIE
   add constraint FK_WATCHLIS_WATCHLIST_WATCHLIS foreign key (ID_WATCH_LIST)
      references WATCHLIST (ID_WATCH_LIST)
go

alter table WATCHLIST_SERIE
   add constraint FK_WATCHLIS_WATCHLIST_SERIE foreign key (ID_SERIE)
      references SERIE (ID_SERIE)
go

