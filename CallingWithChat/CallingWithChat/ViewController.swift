//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Licensed under the MIT License.
//

import UIKit

class ViewController: UIViewController {
    
    private var groupCallWithChatViewController: GroupCallWithChatViewController?
    private var teamsMeetingViewController: TeamsMeetingViewController?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground
        
        let teamMeetingLabel = UILabel()
        teamMeetingLabel.text = "Join a Teams meeting and become a participant in the call and chat thread once admitted to the meeting."
        teamMeetingLabel.lineBreakMode = .byWordWrapping
        teamMeetingLabel.numberOfLines = 0
        teamMeetingLabel.sizeToFit()
        teamMeetingLabel.translatesAutoresizingMaskIntoConstraints = false
        
        let teamsMeetinButton = UIButton()
        teamsMeetinButton.layer.cornerRadius = 10
        teamsMeetinButton.backgroundColor = .systemBlue
        teamsMeetinButton.setTitle("Demo Teams meeting call with chat", for: .normal)
        teamsMeetinButton.addTarget(self, action: #selector(startTeamsMeetingDemo), for: .touchUpInside)
        teamsMeetinButton.translatesAutoresizingMaskIntoConstraints = false
        
        
        let groupCallLabel = UILabel()
        groupCallLabel.text = "Join a group call and chat thread that user is a participant of before joining."
        groupCallLabel.lineBreakMode = .byWordWrapping
        groupCallLabel.numberOfLines = 0
        groupCallLabel.sizeToFit()
        groupCallLabel.translatesAutoresizingMaskIntoConstraints = false
        
        let groupCallButton = UIButton()
        groupCallButton.layer.cornerRadius = 10
        groupCallButton.backgroundColor = .systemBlue
        groupCallButton.setTitle("Demo Goup call with chat", for: .normal)
        groupCallButton.addTarget(self, action: #selector(startGroupCallMeetingDemo), for: .touchUpInside)
        groupCallButton.translatesAutoresizingMaskIntoConstraints = false
        
        let margin: CGFloat = 32.0
        let verticalStackView = UIStackView(arrangedSubviews: [
            teamMeetingLabel,
            teamsMeetinButton,
            groupCallLabel,
            groupCallButton])
        verticalStackView.setCustomSpacing(margin / 2, after: teamMeetingLabel)
        verticalStackView.setCustomSpacing(margin, after: teamsMeetinButton)
        verticalStackView.setCustomSpacing(margin / 2, after: groupCallLabel)
        verticalStackView.axis = .vertical
        verticalStackView.alignment = .fill
        verticalStackView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(verticalStackView)
        
        let margins = view.safeAreaLayoutGuide
        let constraints = [
            verticalStackView.centerXAnchor.constraint(equalTo: margins.centerXAnchor),
            verticalStackView.centerYAnchor.constraint(equalTo: margins.centerYAnchor),
            verticalStackView.leadingAnchor.constraint(equalTo: margins.leadingAnchor, constant: margin),
            verticalStackView.trailingAnchor.constraint(equalTo: margins.trailingAnchor, constant: -margin),
        ]
        NSLayoutConstraint.activate(constraints)
    }
    
    @objc private func startTeamsMeetingDemo() {
        let teamsMeetingViewController = TeamsMeetingViewController()
        self.teamsMeetingViewController = teamsMeetingViewController
        teamsMeetingViewController.modalPresentationStyle = .fullScreen
        present(teamsMeetingViewController, animated: true, completion: nil)
    }
    
    @objc private func startGroupCallMeetingDemo() {
        let groupCallWithChatViewController = GroupCallWithChatViewController()
        self.groupCallWithChatViewController = groupCallWithChatViewController
        groupCallWithChatViewController.modalPresentationStyle = .fullScreen
        present(groupCallWithChatViewController, animated: true, completion: nil)
    }

}
