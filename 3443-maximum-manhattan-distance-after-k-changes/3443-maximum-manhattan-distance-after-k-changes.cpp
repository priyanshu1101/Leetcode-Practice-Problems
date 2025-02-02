class Solution {
public:
    int maxDistance(string s, int k) {
        int nw=0,ne=0,es=0,sw=0,nwk=k,nek=k,esk=k,swk=k,maxAns=INT_MIN;
        for(char ch:s){
            if(ch=='N'){
                if(esk){
                    es++;
                    esk--;
                }
                else es--;
                if(swk){
                    sw++;
                    swk--;
                }
                else sw--;
                nw++;
                ne++;
            }
            else if(ch=='S'){
                if(nwk){
                    nw++;
                    nwk--;
                }
                else nw--;
                if(nek){
                    ne++;
                    nek--;
                }
                else ne--;
                es++;
                sw++;
            }
            else if(ch=='E'){
                if(nwk){
                    nw++;
                    nwk--;
                }
                else nw--;
                if(swk){
                    sw++;
                    swk--;
                }
                else sw--;
                ne++;
                es++;

            }
            else if(ch=='W'){
                if(nek){
                    ne++;
                    nek--;
                }
                else ne--;
                if(esk){
                    es++;
                    esk--;
                }
                else es--;
                sw++;
                nw++;
            }
            maxAns=max(maxAns,max(nw,max(ne,max(es,sw))));
        }
        return maxAns;
    }
};