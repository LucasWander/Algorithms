

struct UserRepositoryMongo;


struct UserRepositoryMongo* createUserRepositoryMongo();
char* getUserRepositoryMongoName(struct UserRepositoryMongo *repositoryMongodb);

void setUserRepositoryMongoName(struct UserRepositoryMongo *repositoryMongodb, char *name);
