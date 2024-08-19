#include "philosophers_bonus.h"

int	main(int argc, char	**argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		print_error("The arguments are different");
	handle_args_error(argc, argv, &info);
	info_init(&info);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
}