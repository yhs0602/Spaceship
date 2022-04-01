#ifndef __LOG_H
#define __LOG_H

#ifdef DEBUG
#define LOGVAR FILE* logfp;
#define LOGINIT logfp=fopen("log.log","wt");if(!logfp){MessageBox(0,"logerror","",0);return -1;}

#define LOGEND fclose(logfp);
#define LOGOUT(s) fprintf(logfp,"%d %s\n",__LINE__,s);
#define VAROUT(vnam,val) fprintf(logfp,"%d %s %lf\n",__LINE__,vnam,(double)val);
#else
#define LOGVAR
#define LOGINIT
#define LOGEND 
#define LOGOUT(s) 
#define LOGVAR(vnam,val)
#endif
#endif

