#include <stdlib.h>
#include "community.h"
#include "interface.h"

TAD_community clean(TAD_community com){
	cleanPosts(&com);

	cleanUsers(&com);

	cleanTags(&com);

	cleanDatas(&com);

	free(com);

	return com;
}
