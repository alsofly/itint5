//将十进制数转换为excel数
string decToExcel(int decNum) {
    string rtn;
    do
    {
        int res = (decNum - 1) % 26;
        decNum = (decNum - 1) / 26;
        rtn = char('A' + res) + rtn;
    } while ( decNum );
    return rtn;
}
//将excel数转换为十进制数
int excelToDec(string excelNum) {
    int tot(0);
    for ( int i = 0, len = excelNum.size(); i < len; ++i )
    {
        int curr = excelNum[i] - 'A' + 1;
        tot = tot * 26 + curr;
    }
    return tot;
}