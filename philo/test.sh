echo "testing ./philo 5 800 200 200 5"
for i in {1..200}
do
    result=$(./philo 5 80 20 20 5 | grep "is eating" | wc -l)
    if [ "$result" -ne 25 ]; then
        echo "Error: Expected 25, but got $result"
    else
        echo "Passed"
    fi
done

# echo "testing ./philo 5 80 20 20 5"
# for i in {1..20}
# do
#     ./philo 5 80 20 20 5 | grep "is eating" | wc -l
# done