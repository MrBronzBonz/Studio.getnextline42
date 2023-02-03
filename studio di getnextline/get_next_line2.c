
#include	"get_next_line.h"

char	*ft_linlett(char *iniz)
{
	int	i; //semplice int da usare come contatore
	char	*line; //stringa in cui trascrivere i frammenti letti

	if (!iniz || !iniz[0]) //verifica esistenza del contatore
		return (NULL);
	i = 0;
	while (iniz[i] && iniz[i] != '\n') //portiamo il contatore a fine frammento letto
		i++;
	if (iniz[i] == '\n') //superiamo lo \n per creare lo spazio terminale \0
		i++;
	line = (char*)malloc(1 + i * sizeof(char)); //diamo alla linea la dimensione del frammento letto
	if(!line) // gestiamo possibilita' d'errore
		return (NULL);
	i = 0; //reset contatore
	while (iniz[i] && iniz[i] !='\n') //copiamo il tank (ovvero iniz) nella line
	{
		line[i] = iniz[i];
		i++;
	}
	if (iniz[i] == '\n') //aggiungiamo il terminatore accapo e uno spazio vuoto per \0
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_mviniz(char *iniz)
{
	char	*newbuff; //nuovo buffer
	int		i; // i e j sono semplici contatori
	int		j;

	i = 0;
	while (iniz[i] && iniz[i] != '\n') //arriviamo a fine frammento
		i++;
	if (iniz[i] == '\0') //gestione errore
	{
		free(iniz);
		return (NULL);
	}
	i += (iniz[i] == '\n'); // superiamo \n per fare il posto allo \0 (forma per risparmiarte spazio)
	newbuff = (char*)malloc(1 + ft_strlen(iniz) - i);
	if (!newbuff)
		return (NULL);
	j = 0;
	while (iniz[i + j])
	{
		newbuff[j] = iniz[i + j];
		j++;
	}
	newbuff[j] = '\0';
	free(iniz);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	char		*t; //buffer ausiliario?
	int			fdl;
	static char	*tank; //buffer statico

	if (fd < 0 || BUFFER_SIZE <= 0) //condizione di esistenza del file e di buffersize
		return (NULL);
	fdl = 1; //chiedere chatgpt perche'impostare il file a 1
	t = (char*)malloc(1 + BUFFER_SIZE * sizeof(char)); //impostare la dimensione del frammento da leggere
	if (!t)
		return (NULL);
	while(!(ft_strchr(tank, '\n')) && fdl !=0) //finche'non si trova il terminatore \n nella stringa
	{
		fdl = read(fd, t, BUFFER_SIZE); //leggi il file
		if (fdl == -1) //se non esiste o fa errore libera memoria e torna NULL
		{
			free(t);
			return (NULL);
		}
		t[fdl] = '\0';
		tank = ft_strjoin(tank, t); //il buffer statico diventa l'unione di e stesso con l'ausiliario
	}
	free(t); //possiamo quindi liberare l'ausiliario
	t = ft_linlett(tank); //impostiamo quindi il buffer ausiliario con la funzione di lettura
	tank = ft_mviniz(tank);
	return (t);
}
