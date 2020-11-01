bool check::hangeulCheck(char& s){
    // cout << s << endl;
    string r = "¤¡";
    string h = "¤¾";
    
    if(s >= r[0] && s <= h[0]) return false;
    
    if(bool(s&0x80) != 1) return false; 
    
    return true;
}
