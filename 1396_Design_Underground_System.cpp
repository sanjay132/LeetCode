class UndergroundSystem {
private:
    // checkInMap (ID, <startStation Name, start Time)
    unordered_map<int, pair<string,int>> checkInMap;

    // Map of <{start Station,End Station}, {time taken and number of client}
    map<pair<string,string>,pair<int,int>> inOutMap;
public:
    UndergroundSystem() {
        
    }

    void checkIn(int id, string stationName, int t) {
        // directly insert into the checkInMap 
        // with ID as key and {stationName and CheckIn Time}
        checkInMap[id]={stationName,t};
    }

    void checkOut(int id, string stationName, int t) {
        //if id is present in checkInMap
        if(checkInMap.find(id) != checkInMap.end()){
            // get the CheckIn station and InTime from the id of the customer
            // from the chieckInMap
            auto p = checkInMap[id];

            // get the diff of time taken for the start and dest
            int diff = t-p.second;
            pair<string,string> temp(p.first, stationName);
            auto itr = inOutMap.find(temp);
            // check if (Start and End) station are present in inOutMap
            // if present updaed the (Value of this Map)(add the time take b/w)
            // start and End station and increase the count of passenger
            if(itr != inOutMap.end()){
                auto tmp = *itr;
                auto op = tmp.second;
                inOutMap.erase(temp);
                op.first += diff;
                op.second += 1;
                inOutMap.insert({temp, op});
            }else{
                // this (start, End pair is for the first time)
                // add the value as (time Taken, 1 as number of passenger)
                pair<int,int> tmp;
                inOutMap.insert({{p.first,stationName},{diff,1}});
            }
        }
    }

    double getAverageTime(string startStation, string endStation) {
        // return the avg from the (value of inOutMap)
        // time/passenger Count
        auto p = inOutMap[{startStation, endStation}];
        
        return ((double)p.first/(double)p.second);
    }
};
