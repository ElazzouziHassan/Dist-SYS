struct strings{
  string srt1;
  string str2;
}
program CONCATPROG {
    version CONCATVERS {
        string CONCATENATE(string, string) = 1;
    } = 1;
} = 0x31230000;