/*By Sean Stepanik*/
import io.StdIn._
type TimeTuple = (Int, Int, Int, Int) 
print("please input the time in seconds: ")
var input = readInt()
val result = time(input)
println(result._1+" days "+ result._2+" hours "+ result._3 +" minutes "+ result._4 + " seconds ")

def time(totalSeconds:Int):TimeTuple = {
    var days = totalSeconds/86400
    var hours = (totalSeconds-(days.toInt*86400))/3600
    var mins = (totalSeconds-(days.toInt*86400)-(hours.toInt*3600))/60
    var secs = totalSeconds-(days.toInt*86400)-(hours.toInt*3600)-(mins.toInt*60)

    (days, hours, mins, secs)//last expression
}
