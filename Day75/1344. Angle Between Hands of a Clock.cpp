class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a=abs(30*hour-5.5*minutes);
        a=min(a,360-a);
        return a;
        
    }
};