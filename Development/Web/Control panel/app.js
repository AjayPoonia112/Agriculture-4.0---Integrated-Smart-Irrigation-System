@ -0,0 +1,76 @@
document.addEventListener('DOMContentLoaded', function () {
    const temperatureElement = document.getElementById('temperature');
    const soilMoistureElement = document.getElementById('soilMoisture');
    const startAutomaticButton = document.getElementById('startAutomatic');
    const stopAutomaticButton = document.getElementById('stopAutomatic');

    // Fetch initial temperature data

    // soildata
    async function fetchSensorData() {
        //var temperatureData = fetchSensorData1();
        var temp =0;
        var temp1 =0;
        await fetch('https://blr1.blynk.cloud/external/api/get?token=kTtyC1yLrOlg1tAkv2bix6isteuYmXAh&V4')
            .then(response => response.json())
            .then(data => {
                //console.log(data); // Log the entire data object to inspect its structure
                 // Assuming temperature data is in the first element of the array
                temp = data; // Assuming soil moisture data is in the second element of the array
                console.log(temp)
                //console.log(soilMoistureData)
                // updateSensorReadings({ temperature: temperatureData, soilMoisture: soilMoistureData });
            })
            .catch(error => {
                console.error('Error fetching sensor data:', error);
            });

            await fetch('https://blr1.blynk.cloud/external/api/get?token=kTtyC1yLrOlg1tAkv2bix6isteuYmXAh&V5')
            .then(response => response.json())
            .then(data => {
                //console.log(data); // Log the entire data object to inspect its structure
                 // Assuming temperature data is in the first element of the array
                temp1 = data; // Assuming soil moisture data is in the second element of the array
                console.log(temp1)
                //console.log(soilMoistureData)
                updateSensorReadings({ temperature: temp1, soilMoisture: temp });
            })
            .catch(error => {
                console.error('Error fetching sensor data:', error);
            });
    }

    // Update sensor readings on the UI
    function updateSensorReadings(data) {
        try {
            if (data.temperature !== undefined) {
                temperatureElement.textContent = `${data.temperature} °C`;
            } else {
                console.error('Temperature data is undefined:', data);
            }

            if (data.soilMoisture !== undefined) {
                soilMoistureElement.textContent = `${data.soilMoisture}%`;
            } else {
                console.error('Soil moisture data is undefined:', data);
            }
        } catch (error) {
            console.error('Error updating sensor readings:', error);
        }
    }

    // Set up event listeners for control actions
    startAutomaticButton.addEventListener('click', fetchSensorData);
    stopAutomaticButton.addEventListener('click', stopAutomaticMode);

    // Function to stop automatic mode
    function stopAutomaticMode() {
        console.log('Automatic mode stopped');
    }

    // Fetch initial sensor data on page load
    fetchSensorData();

    // Set up interval to fetch sensor data periodically
    setInterval(fetchSensorData, 5000); // Fetch every 5 seconds
});
