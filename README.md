# AP HW6
In this project, we implement different functions and classes using STL and C++ containers.

## Question1 (Gradient descent) 
In this question we implemented a function template using funtion call back (input function to use gradient descent algorithm on).
`gradient_descent` function takes initial value, step size and the function (lambda, function object or function pointer) and returns the smallest value that it can find.
```cpp
template <typename T, typename FUNC>
T gradient_descent(T ivalue, T step, FUNC func = FUNC())
```

## Question2 (Patient sort) 
In this question, we have a sort function. it takes a vactor of `Patient` and sorts them according to the `comp` function.
```cpp
inline void sort(std::vector<Patient>&)
```
The `comp` function uses the defined pattern to compare determine which patient has a higher risk of lung cancer.
```cpp
inline bool comp(const Patient& P1, const Patient& P2)
```
The `read_file` function uses `regex` to extract patients info from a `.csv` file stored in the resources folder and save them in a vactor of `Patient` class.
```cpp
inline std::vector<Patient> read_file(std::string filename)
```

## Question3 (Flight sort) 
Like question2, in this question we extract flight information (connection time, duration and ...) and sort them in `priority queue`.
Because we are using a `priority queue` of `Flight`, the reading from file and storing in a container should be done in the same `gather_flights` function.
```cpp
inline std::priority_queue<Flight, std::vector<Flight>, comp> gather_flights(std::string filename)
```

## Question4 (Kalman filter) 
In this question we emplement the kalman filter algorithm. 
Using `std::accumulate()` we read data from a vactor of `Sensor` and add them with respect to kalman filter principle.
```cpp
Vector2D kalman_filter(std::vector<Sensor> sensors)
```
