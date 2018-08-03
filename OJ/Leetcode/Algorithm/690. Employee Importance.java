/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer,Employee> map = getEmployeeImportanceMap(employees);
        return employeeImportanceDFS(map.get(id),map);
    }

    public Map<Integer,Employee> getEmployeeImportanceMap(List<Employee> employees){
        Map<Integer,Employee> map = new HashMap<Integer,Employee>();
        for(Employee employee:employees)
            map.put(employee.id,employee);
        return map;
    }

    public int employeeImportanceDFS(Employee employee, Map<Integer,Employee> map){
        int sum = employee.importance;
        List<Integer> subordinates = employee.subordinates;
        if(subordinates.size() == 0) return sum;
        for(int i=0;i<subordinates.size();i++)
            sum+=employeeImportanceDFS(map.get(subordinates.get(i)),map);
        return sum;
    }
}
