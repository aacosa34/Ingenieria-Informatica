class matriz_sesgada{
    private:
        vector<list<int>> datos;
    public:
        ...
        int & operator()(const int & fil, const int & col){
            list<int>::iterator it = datos[fil].begin();
            for(int i = 0; i <= col && it != datos[fil].end(); ++it, i++){}

            return *it;
        }

        class iterador_pares{
            private:
                vector<list<int>>::iterator it, fin;
                list<int>::iterator lit, lfin;
            public:
                iterator() = default;

                iterator(const iterador_pares & otro) = default;

                ~iterator() = default;

                bool & operator==(const iterador_pares & otro){
                    return it == otro.it;
                }

                bool & operator!=(const iterador_pares & otro){
                    return it != otro.it;
                }

                list<int> & operator*(){
                    return *it;
                }

                iterador_pares & operador++(){
                    it = datos.begin();
                    fin = datos.end();
                    lit = *it.begin();
                    ++lit;
                    
                    ++it;
                    while (it != fin && *lit % 2 != 0){
                        while(lit != *it.end() && *lit % 2 != 0)
                            ++lit;
                        
                        if(lit == *it.end())
                            ++it;
                    }

                    return *this;
                }

            friend class matriz_sesgada;
                
        };

        iterador_pares & begin(){
            iterador_pares dit;
            dit.it = datos.begin();
            dit.fin = datos.end();
            dit.lit = *(dit.it).begin();

            if(*(dit.lit) % 2 != 0 && dit.lit != *(dit.it).end()){
                ++dit;
            }

            return *this;
        }

        iterador_pares & end(){
            iterador_pares dit;
            dit.it = datos.end();
            dit.fin = datos.end();
            dit.lit = datos.end();
            dit.lfin = datos.end();

            return *this;
        }
}