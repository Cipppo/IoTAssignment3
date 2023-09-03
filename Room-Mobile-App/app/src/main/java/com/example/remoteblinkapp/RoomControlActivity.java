package com.example.remoteblinkapp;

import android.Manifest;
import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.text.style.TabStopSpan;
import android.util.Log;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import java.io.IOException;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;

public class RoomControlActivity extends AppCompatActivity {

    private OutputStream bluetoothOutputStream;

    private Button turnOnLeds;

    private Button turnOffLeds;

    private SeekBar slider;

    private Button sendServoValue;

    private boolean ledState;

    private int servoValue;

    private TextView seekbarValue;

    private BluetoothClientConnectionThread connectionThread;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.room_control_activity);
        ledState = false;
        initUI();
    }

    private void initUI() {
        turnOnLeds = findViewById(R.id.ledTurnOnButton);
        turnOffLeds = findViewById(R.id.ledOffButton);
        slider = findViewById(R.id.seekBar);
        sendServoValue = findViewById(R.id.sendServoValuesButton);
        seekbarValue = findViewById(R.id.seekbarValue);
        turnOnLeds.setOnClickListener((v) -> sendLedOnMessage());
        turnOffLeds.setOnClickListener((v) -> sendLedOffMessage());
        sendServoValue.setOnClickListener((v) -> sendServoMessage());

        slider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                seekbarValue.setText(String.valueOf(i));
                servoValue = i;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    private void sendLedOnMessage() {
        new Thread(() -> {
            try {
                String message = "5555";
                bluetoothOutputStream.write(message.getBytes(StandardCharsets.UTF_8));
                ledState = true;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    private void sendLedOffMessage() {
        new Thread(() -> {
            try {
                String message = "6666";
                bluetoothOutputStream.write(message.getBytes(StandardCharsets.UTF_8));
                ledState = false;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    private void sendServoMessage(){
        new Thread(() -> {
            try{
                String message = String.valueOf(servoValue);
                bluetoothOutputStream.write(message.getBytes(StandardCharsets.UTF_8));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    @SuppressLint("MissingPermission")
    @Override
    protected void onStart() {
        super.onStart();
        Intent intent = getIntent();
        BluetoothDevice bluetoothDevice = intent.getParcelableExtra(ScanActivity.X_BLUETOOTH_DEVICE_EXTRA);
        BluetoothAdapter btAdapter = getSystemService(BluetoothManager.class).getAdapter();
        Log.i(C.TAG, "Connecting to " + bluetoothDevice.getName());
        connectionThread = new BluetoothClientConnectionThread(bluetoothDevice, btAdapter, this::manageConnectedSocket);
        connectionThread.start();
    }

    private void manageConnectedSocket(BluetoothSocket socket){
        try{
            bluetoothOutputStream = socket.getOutputStream();
            Log.i(C.TAG, "Connection successful!");
        }catch(IOException e){
            Log.e(C.TAG, "Error occurred when creating output stream", e);
        }
    }

    @Override
    protected void onStop(){
        super.onStop();
        connectionThread.cancel();
    }

}
