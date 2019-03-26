#include <libxml/parser.h>  
#include <libxml/xmlmemory.h> 
#include <interface.h>
#include <string.h>

#include "pair.h"
#include "user.h"
#include "list.h"
#include "date.h"
#include "community.h"
#include "common.h" 
#include "query1.h" 
#include "query2.h" 
#include "query3.h" 
#include "query4.h" 
#include "query5.h" 
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "query9.h"
#include "query10.h"
#include "query11.h"

//query 1
STR_pair info_from_post(TAD_community com, long id){
	STR_pair resp = query1aux(com,id); 
	return resp;
}

//query 2
LONG_list top_most_active(TAD_community com, int N)
{
	LONG_list resp = query2aux(com,N); 
	return resp;
}

//query 3
LONG_pair total_posts(TAD_community com, Date begin, Date end)
{
	LONG_pair r = query3aux(com,begin,end); 	 
	return r;
}

//query 4
LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end)
{
	LONG_list r = query4aux(com, tag, dateConvert(begin), dateConvert(end));
	return r;
}

//query 5
USER get_user_info(TAD_community com, long id)
{	
	USER r = query5aux(com,id);		
	return r;
}

//query 6
LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end)
{
	LONG_list r = query6aux(com,N,begin,end); 
	return r;
}

//query 7
LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end)
{
	LONG_list r = query7aux(com, N, begin, end);

	return r;
}

//query 8
LONG_list contains_word(TAD_community com, char* word, int N)
{
	LONG_list r = create_list(N);
	query8aux(com, word, N, &r);
	return r;
}

//query 9
LONG_list both_participated(TAD_community com, long id1, long id2, int N)
{
	LONG_list r = create_list(N);
	query9aux(com, id1, id2, N, &r);
	return r;
}

//query 10
long better_answer(TAD_community com, long id)
{
	long r = GetBetterAnswer(com, id);

	return r;
}

//query 11
LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end)
{
	LONG_list r = create_list(N);
	query11aux(com, N, dateConvert(begin), dateConvert(end), &r);
	return r;
}