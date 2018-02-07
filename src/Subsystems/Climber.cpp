#include "Climber.h"

#define CLIMB 1.0
#define DESCEND -1.0

Climber::Climber() : frc::Subsystem("Climber")
{
	a = new WPI_TalonSRX(CLIMBER_MOTOR_1_ID); // Climber Motor 1
	b = new WPI_TalonSRX(CLIMBER_MOTOR_2_ID); // Climber Motor 2
	b->SetInverted(false); // FIXME: May have to invert the other motor
	a->SetInverted(false); // FIXME: May have to invert the other motor
	enc = new Encoder(2, 3);


	a->Set(ControlMode::PercentOutput, 0);
	b->Set(ControlMode::PercentOutput, 0);
	EncoderValue = 0;
	enc->Reset();


}

void Climber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Climber::Climb()
{
	a->Set(CLIMB);
	b->Set(CLIMB);
	EncoderValue = enc->Get();
	SmartDashboard::PutNumber("Climber Encoder: ", EncoderValue);
}

void Climber::Descend()
{
	a->Set(DESCEND);
	b->Set(DESCEND);
	EncoderValue = enc->Get();
	SmartDashboard::PutNumber("Climber Encoder: ", EncoderValue);
}

void Climber::Stop()
{
	a->Set(0.0);
	b->Set(0.0);
}

int Climber::GetPosition()
{
	return enc->Get();
}
