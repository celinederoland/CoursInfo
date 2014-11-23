void server_v3() 
{ 
	pthreadt T[NB_THREADS]; 
	int i; 
	for (i=0 ; i<NB_THREADS; ++i) 
	{ 
		pthread_create(T+i, NULL, (void * (*)(void*))faire_le_boulot,NULL); 
	} 
	for (i=0 ; i < NB_THREADS ; ++i) 
	{ 
		pthread_join(T[i],NULL); 
	} 
} 
void faire_le_boulot 
{ 
	requete* req;
	page_web* page;
	while( pas_termine() ) 
	{ 
		attendre_une_requete(\& req); 
		chercher_page_en_cache(\& req, \& page); 
		if (page_pas_en_cache(\& page)) 
		{ 
			lire_page_sur_disque(\& req, \& page); 
		} 
		envoyer_requete(\& req, \& page); 
	} 
} 
