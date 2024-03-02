# echo "testing ./philo 5 800 200 200 5"
# for i in {1..5}
# do
#   ./philo 5 800 200 200 & sleep 5 && kill $!
# done

echo "testing ./philo 5 80 20 20 5"
for i in {1..20}
do
    ./philo 5 80 20 20 5 | grep "is eating" | wc -l
done