#define ri register int

template <typename T>inline void redi(T& t)
{
    ri c=getchar();t=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
    redi(t);redi(args...);
}
