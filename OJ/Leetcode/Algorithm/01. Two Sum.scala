object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val idxMap = scala.collection.mutable.Map[Int, Int]()
        nums.zipWithIndex foreach { pair =>
            idxMap.get(target - pair._1) match {
                case Some(idx) => return Array(idx, pair._2)
                case _ => idxMap += pair
            }
        }
        Array[Int]()
    }
}
