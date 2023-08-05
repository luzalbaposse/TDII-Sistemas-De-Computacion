class Mate:
    def __init__(self, temp, yerba, lt):
        self.temp = temp
        self.yerba = yerba
        self.lt = lt

    def calentar_el_agua(self):
        while self.temp < 75:
            self.temp += 1
            print(f"Calentando el agua... Temperatura actual: {self.temp} grados")
        self.sacar_el_agua_del_fuego()

    def sacar_el_agua_del_fuego(self):
            print("¡Sacando el agua del fuego!")
            self.temp = 75

    def llenar_termo(self):
        if self.lt <= 0.2:
            print("¡Llenando el termo!")
            self.lt = 0.5
        else:
            print("No es necesario llenar el termo, todavía hay suficiente agua.")

mate = Mate(20, 0.5)
mate.llenar_termo()
mate.calentar_el_agua()
mate.llenar_termo()
mate.sacar_el_agua_del_fuego()
mate.llenar_termo()
