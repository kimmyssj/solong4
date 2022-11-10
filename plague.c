void	plague_initialize(char **map, int x, int y)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		map[y + 1][x] = '2';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		map[y - 1][x] = '2';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		map[y][x + 1] = '2';
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	map[y][x - 1] = '2';
}

void	plague_component(char **map, t_plague *p)
{
	if ((map[p->y + 1][p->x] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y - 1][p->x] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y][p->x + 1] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y][p->x - 1] == '2' && map[p->y][p->x] == '0') ||
		(map[p->y + 1][p->x] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y - 1][p->x] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y][p->x + 1] == '2' && map[p->y][p->x] == 'C') ||
		(map[p->y][p->x - 1] == '2' && map[p->y][p->x] == 'C'))
	{
		p->flag = 0;
		map[p->y][p->x] = '2';
	}
}

void	plague_active(char **map, int idx)
{
	t_plague	p;

	p.flag = 0;
	while (p.flag == 0)
	{
		p.y = 0;
		p.flag = 1;
		while (++p.y < idx - 1)
		{
			p.x = 0;
			while (map[p.y][++p.x] != '\n')
				plague_component(map, &p);
		}
	}
}
