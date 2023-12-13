document.addEventListener('DOMContentLoaded', function () {
  const temperatureElement = document.getElementById('temperature');
  const soilMoistureElement = document.getElementById('soilMoisture');
  const controlModeSelect = document.getElementById('controlMode');
  const startAutomaticButton = document.getElementById('startAutomatic');
  const stopAutomaticButton = document.getElementById('stopAutomatic');

  // Fetch initial sensor data
  function fetchSensorData() {
    // Replace this with actual API endpoint to fetch sensor data
    // For simplicity, using mock data here
    const mockData = {
      temperature: getRandomNumber(20, 30),
      soilMoisture: getRandomNumber(30, 70),
    };

    updateSensorReadings(mockData);
  }

  // Update sensor readings on the UI
  function updateSensorReadings(data) {
    temperatureElement.textContent = `${data.temperature} °C`;
    soilMoistureElement.textContent = `${data.soilMoisture}%`;
  }

  // Set up event listeners for control actions
  startAutomaticButton.addEventListener('click', startAutomaticMode);
  stopAutomaticButton.addEventListener('click', stopAutomaticMode);

  // Function to start automatic mode
  function startAutomaticMode() {
    // Replace the URL with your backend API endpoint for starting automatic mode
    console.log('Automatic mode started');
  }

  // Function to stop automatic mode
  function stopAutomaticMode() {
    // Replace the URL with your backend API endpoint for stopping automatic mode
    console.log('Automatic mode stopped');
  }

  // Helper function to get a random number in a range
  function getRandomNumber(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
  }

  // Fetch initial sensor data on page load
  fetchSensorData();

  // Set up interval to fetch sensor data periodically
  setInterval(fetchSensorData, 5000); // Fetch every 5 seconds
});

