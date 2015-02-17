/**
 * Definition for an interval
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> ret = new ArrayList<Interval>();
        for(Interval interval : intervals){
            if(interval.end < newInterval.start){
                ret.add(interval);
            }else if(interval.start > newInterval.end){
                ret.add(interval);
            }else{
                newInterval = new Interval(Math.min(interval.start, newInterval.start),
                                           Math.max(interval.end, newInterval.end));
            }
        }
        for(int i = 0; i < ret.size(); i++){
            if(ret.get(i).start > newInterval.start){
                ret.add(i, newInterval);
                return ret;
            }
        }
        ret.add(newInterval);
        return ret;
    }
}
