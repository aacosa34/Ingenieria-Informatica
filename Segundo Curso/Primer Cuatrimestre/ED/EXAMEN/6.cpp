void contar(const vector<set<int>> &V, map<int,int> &veces){
    vector<set<int>>::iterator pos_vector = V.begin();
    vector<set<int>>::iterator pos_vector_sig = V.begin();
    ++pos_vector_sig;
    int num_veces;
    
    while(pos_vector_sig != V.end()){
        set<int>::iterator pos_ini = *pos_vector.begin();
        set<int>::iterator sig_set = *pos_vector_sig.begin();

        while (pos_ini != *pos_vector.end()){
            num_veces = 1;
            while (sig_set != *pos_vector_sig.end()){
                if(*pos_ini == *sig_set){
                    num_veces++;   // Aparece, luego una vez más
                }
                ++sig_set; // en cualquier caso;
            }
            veces[*pos_ini] = num_veces;
            ++pos_ini;
            num_veces = 0;
        }
        ++pos_vector;
        ++pos_vector_sig;
    }
}