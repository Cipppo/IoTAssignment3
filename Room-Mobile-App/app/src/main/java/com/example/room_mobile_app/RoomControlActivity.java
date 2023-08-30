package com.example.room_mobile_app;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;

public class RoomControlActivity extends AppCompatActivity {


    private OutputStream bluetoothOutputStream;
    private Button remoteButton;
    private boolean ledState;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.room_control_activity);
        ledState = false;
        initUI();
    }


    private void initUI() {
        remoteButton = findViewById(R.id.remotebutton);
        remoteButton.setBackgroundColor(Color.LTGRAY);
        remoteButton.setEnabled(false);
        remoteButton.setOnClickListener((v) -> sendMessage());
    }

    private void sendMessage() {
        new Thread(() -> {
            try {
                String message = ledState ? "off\n" : "on\n";
                bluetoothOutputStream.write(message.getBytes(StandardCharsets.UTF_8));
                ledState = !ledState;
                runOnUiThread(() -> remoteButton.setBackgroundColor(ledState? Color.GREEN : Color.RED));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
