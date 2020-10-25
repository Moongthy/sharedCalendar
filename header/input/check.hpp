
// °¡³ª´Ù¶ó,,,ÆR = true ¹ÝÈ¯
// ¤¡¤¤¤§¤© ¤± ,, ¤² ,,,¤¾ = false ¹ÝÈ¯
bool check::hangeulCheck(string& s){
    // cout << s << endl;
    string r = "¤¡";
    string h = "¤¾";
    for(char c : s)
        if(c >= r[0] && c <= h[0])
            return false;
    for(int i = 0; i < s.size(); ++i){
        if(bool(s[i]&0x80) != 1)
            return false; 
    }
    return true;
}
