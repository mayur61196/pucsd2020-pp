USE  ACL;

CREATE TABLE IF NOT EXISTS user(
    user_id             INT         PRIMARY KEY,
    first_name          CHAR(30)    NOT NULL,
    last_name           CHAR(30)    NOT NULL,
    password            VARBINARY(128)    NOT NULL,
    user_creation_date       DATETIME    DEFAULT CURRENT_TIMESTAMP
)

CREATE TABLE IF NOT EXISTS group(
    group_id            INT         PRIMARY KEY,
    group_name          CHAR(30)    NOT NULL,            
    group_creation_date       DATETIME    DEFAULT CURRENT_TIMESTAMP
)

CREATE TABLE IF NOT EXISTS file (
    file_id             INT         PRIMARY KEY,
    file_name           CHAR(30)    NOT NULL,
    file_path           CHAR(100)   NOT NULL 
)


CREATE TABLE IF NOT EXISTS folder (
    folder_id             INT         PRIMARY KEY,
    folder_name           CHAR(100)   NOT NULL,
    folder_path           CHAR(100)   NOT NULL
)


CREATE TABLE IF NOT EXISTS permission (
    permission_id       INT         PRIMARY KEY,
    per_type            CHAR(30)    NOT NULL
)


CREATE TABLE IF NOT EXISTS user_group_mapping (
    user_id             INT,
    group_id            INT,
    PRIMARY KEY(user_id,group_id),
    FOREIGN KEY(user_id) 
       REFERENCES user(user_id),
    FOREIGN KEY(group_id) 
       REFERENCES group(group_id)
)


CREATE TABLE IF NOT EXISTS file_folder_mapping (
    folder_id           INT,
    file_id             INT,
    PRIMARY KEY(folder_id,file_id),
    FOREIGN KEY(folder_id) 
       REFERENCES folder(folder_id),
    FOREIGN KEY(file_id) 
       REFERENCES file(file_id),
    )

CREATE TABLE IF NOT EXISTS folder_mapping(
    parent_folder_id    INT,
    child_folder_id     INT,
    PRIMARY KEY(parent_folder_id,child_folder_id),
    FOREIGN KEY(parent_folder_id) 
       REFERENCES folder(folder_id),
    FOREIGN KEY(child_folder_id) 
       REFERENCES folder(folder_id)
    )

CREATE TABLE IF NOT EXISTS file_permission(
    user_id             INT,
    file_id             INT,
    permission_id       INT,
    PRIMARY KEY(user_id,file_id),
    FOREIGN KEY(user_id) 
       REFERENCES user(user_id),
    FOREIGN KEY(file_id) 
       REFERENCES file(file_id),
    FOREIGN KEY(permission_id) 
       REFERENCES permission(permission_id)
)

CREATE TABLE IF NOT EXISTS folder_permission(
    user_id             INT,
    folder_id           INT,
    permission_id       INT,
    PRIMARY KEY(user_id,folder_id),
    FOREIGN KEY(user_id) 
       REFERENCES user(user_id),
    FOREIGN KEY(folder_id) 
       REFERENCES folder(folder_id),
    FOREIGN KEY(permission_id) 
       REFERENCES permission(permission_id)
)

