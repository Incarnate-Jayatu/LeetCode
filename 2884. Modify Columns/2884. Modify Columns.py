1import pandas as pd
2
3def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
4    employees.salary *= 2
5    return employees