/* LogTM: Checker function that verifies sortedness of the index array */
int logTM_check_sortedness(void * array,int argc,void **argv)
{
    int len = *argv[0];
        for(i=0; i<len; i++)
    {
         if(array[i] > array[i+1])
         {
              return(-1); //Function failed - Invariant does not hold
         }
    }
    return(0);
}
