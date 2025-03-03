/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:34:38 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/03 13:34:47 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_array(int arr[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	get_max(int arr[], int len)
{
	int	mx;
	int	i;

	mx = arr[0];
	i = 0;
	while (i < len)
	{
		if (arr[i] > mx)
			mx = arr[i];
		i++;
	}
	return (mx);
}
// {25, 4, 45, 123, 99}

void	count_sort(int arr[], int len, int exp)
{
	int	output[len];
	int	count[10];
	int	i;

	count[10] = {0};
	i = 0;
	while (i < len)
	{
		count[(arr[i] / exp) % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = len - 1;
	while (i >= 0)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		i--;
	}
	i = 0;
	while (i < len)
	{
		arr[i] = output[i];
		i++;
	}
}

void	radix_sort(int arr[], int len)
{
	int	m;
	int	exp;

	m = get_max(arr, len);
	exp = 1;
	while (m / exp)
	{
		count_sort(arr, len, exp);
		exp *= 10;
	}
}

int	main(void)
{
	int arr[] = {175, 4, 78, 5485, 9, 2, 66, 57};
	int len;

	len = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	print_array(arr, len);

	radix_sort(arr, len);

	printf("Sorted array: ");
	print_array(arr, len);
	return (0);
}